# 数值优化SIMD

## 1、概述

SIMD全称Single Instruction Multiple Data，单指令多数据流，能够读取多个操作数，并把它们打包在大型寄存器的一组指令集。一次获取多个操作数后，存放于一个大型寄存器，再进行运算，从而达到一条指令完成对多个对象计算的效果，实现加速。目前常见编译器对X86-64的CPU上128bit的SIMD计算支持比较好，基本对于大多简单的计算都可以做到使用SIMD做一个简单的优化，但是对于较为复杂的操作依旧需要手动编写相应的C/C++或者汇编代码。

Intel官网上SIMD指令使用的相关指南
 [https://software.intel.com/sites/landingpage/IntrinsicsGuide/#](https://links.jianshu.com/go?to=https%3A%2F%2Fsoftware.intel.com%2Fsites%2Flandingpage%2FIntrinsicsGuide%2F%23)

## 2、简单使用

SIMD这个东西我到现在也不是很会用，包括测试一些例子可能用了SIMD更慢了，而且我的CPU比较老了，只支持AVX2.0(AVX-512好像现在的i9和i7 9800x都已经支持了，不过我这个还在用四代i7的也买不起这玩意)。因此对于双精度浮点型运算，只能一次打包256bit的数据，即四个双精度浮点数。对了这里需要注意的一点是，在使用gcc编译带有immintrin.h头文件函数的代码时，根据你使用的函数类别，需要添加相应的编译选项(老的SSE是默认支持的通常不需要额外添加选项)，如AVX2.0就需要使用-mavx2、FMA需要使用-mfma等等，否则编译会报错。如果你不知道用了什么指令集，但是你确定你的电脑支持这个操作，那么直接-march=native就可以了。其实如果你使用了AVX-512F指令集，那么-mavx512f也可以成功编译，不过如果你的CPU不支持AVX-512F那么你运行编译出来的文件的时候就会提示非法指令(#滑稽)。

### 2.1矢量加法

没错又是矢量相加，这次我们也不搞什么花哨的了，就是C的矢量相加



```cpp
#include <iostream>
using namespace std;
#define N 20000000
int main(){
    double *x,*y,*z;
    x=(double*)malloc(sizeof(double)*N);
    y=(double*)malloc(sizeof(double)*N);
    z=(double*)malloc(sizeof(double)*N);
    for(int i=0;i<N;i++) z[i]=x[i]+y[i];
    free(x);
    free(y);
    free(z);
    return 1;
}
```

然后我们再用SIMD写一个，要使用SIMD技术需要Intrinsics头文件，这其中有好多不同的头文件，具体哪个可以查看我先前有关AVX指令集介绍的文章，不过一般计算用immintrin.h基本就可以了。



```cpp
#include <iostream>
#include <immintrin.h>
#define N 20000000
using namespace std;
int main(){
    double *x,*y,*z,*px,*py,*pz;
    x=(double*)_mm_malloc(sizeof(double)*N,16);//申请内存并且按照2的4次方对齐地址
    y=(double*)_mm_malloc(sizeof(double)*N,16);
    z=(double*)_mm_malloc(sizeof(double)*N,16);
    px=x;py=y;pz=z;
    __m128d vx,vy,vz;// __m128d是SSE指令集中操作双精度浮点数对应的数据类型
    for(int i=0;i<N/2;i++){
        vx=_mm_load_pd(px);//从px指向的内存中取出两个数，放入入vx
        vy=_mm_load_pd(py);//从py指向的内存中取出两个数，放入入vy
        vz=vx+vy;//计算vx+vy并将结果放入vz，这一行也有对应的函数，不过GCC编译的话直接这样写没有什么问题，测试发现VS的编译器和Intel的编译器都不支持这种写法
        _mm_store_pd(pz,vz);//将vz中的结果放入pz指向的内存
        px+=2;//由于前面取出了两个数据，所以指针后移两位
        py+=2;
        pz+=2;
    }
    _mm_free(x);//释放_mm_malloc申请的内存
    _mm_free(y);
    _mm_free(z);
    return 1;
}
```

好了程序写好接下来就是测试了，经过测试两个程序的计算结果都是正确的，由于测计算结果还要写赋值我嫌麻烦就不写了，有兴趣的可以自己赋个值看一下结果对不对。这里就测一下效率，首先依旧是g++的O0条件下的测试。

未使用SIMD的用时



```css
real    0m0.167s
user    0m0.092s
sys     0m0.075s
```

使用SIMD的用时



```css
real    0m0.175s
user    0m0.122s
sys     0m0.053s
```

可以看到O0优化下SIMD较慢，不过二者用时差距也不大，多次测试感觉基本就是这个范围上下波动，可以认为两个效率相当，或者SIMD略慢一点。

接下来是O3条件下测试
 未使用SIMD时



```css
real    0m0.112s
user    0m0.040s
sys     0m0.072s
```

使用SIMD时



```css
real    0m0.113s
user    0m0.044s
sys     0m0.068s
```

二者基本没有区别，我尝试过加大数组维度，但是由于内存只有4G所以增加的也不多，我也尝试过反复相加，最后测试结果都是不论是否使用编译器优化使用SIMD始终没有提高效率。也就是说在这个示例中SIMD是没有作用的，甚至使得计算变慢。

后来看了一些网上的帖子也有人遇到了与我类似的情况。

有人提到了在进行一些简单运算时，编译器会在你没有主动使用SIMD的情况下通过一些优化技术自动转换为SIMD的代码，所以你自己写的使用SIMD的代码最快也不会超过编译器自动优化的结果。

还有一些人说是SIMD的额外开销是比较大的，对于这种简单加法，使用SIMD带来的计算上的效率提升，掩盖不了使用SIMD带来的额外性能损失，可能计算比较复杂时SIMD才有加速的效果。

另外还有一种说法是XMM寄存器总共有8个，而这里并没有把8个寄存器都用上，从而并没有发挥出全部的性能，所以没有效果。

通过g++的-S选项生成汇编代码可以看到，编译器自动优化这部分代码，不论是使用immintrin.h头文件中的函数，还是使用循环直接计算，生成的汇编代码基本相同，也就是说编译器已经自动优化了这部分的运算，因此并没有什么效果。

### 2.2复数数组乘法

复数数组的乘法是我在写一个快速傅里叶变换的实现的时候测试的，发现使用AVX2.0之后效率确实有明显提升，这里简单展示一下

首先是计算的原理，因为复数计算不同于实数，根据实部和虚部的关系，在计算时常常会因为浮点数的位置不同而需要采用不同的运算方式，所以在使用SIMD加速时也需要做一些处理和变化。这里使用AVX2.0指令，一次操作256bit的数据，即4个双精度浮点数，2个双精度复数。因此，这里测试时采用z1[2]与z2[2]两个复数数组进行相乘。具体的计算如下：
 为了方便我们记：
 z1中的两个复数为a0 + i * b0和a1 + i * b1
 z2中的两个复数为c0 + i * d0和c1 + i * d1

这时计算结果就表示为：
 (a0 * c0 - b0 * d0) + i * (a0 * d0 + b0 * c0)和(a1 * c1 - b1 * d1) + i * (a1 * d1+b1 * c1)

对于计算结果可以拆解为两部分：
 {a0 * c0 , a0 * d0 , a1 * c1 , a1 * d1}
 {b0 * d0 , b0 * c0 , b1 * d1 , b1 * c1}
 将这两部分的偶数下标位相减，奇数下标位相加就可以得到最终的计算结果，恰好AVX2.0为我们提供了这条指令。

再进一步分解：
 {a0 , a0 , a1 , a1}
 {c0 , d0 , c1 , d1}
 相乘可以得到第一部分而
 {b0 , b0 , b1 , b1}
 {d0 , c0 , d1 , c1}
 相乘可以得到第二部分

可以看出，复数乘法计算可以通过将z1中的实部取出与z2直接做乘法，再将z1中的虚部取出与z2的实部虚部交换之后的排列做乘法，最终再交错进行加减得到最终结果。

尽管看起来操作十分繁琐，不过幸运的是其实这些操作都可以找到相应的指令的来完成。

在immintrin.h头文件中，有一个__m256d _mm256_permute_pd (__m256d a, int imm8)函数。

这个函数接收一个__m256d变量和一个4位的即时数(0-15的十进制字面值)，根据imm8的每一个二进制位上的数来决定该a中的对应位置的数是保持不变还是替换为其前后的数。最终得到一个新的__m256d变量，并返回。具体的规则如下：
 IF (imm8[0] == 0) dst[63:0] := a[63:0]
 IF (imm8[0] == 1) dst[63:0] := a[127:64]
 IF (imm8[1] == 0) dst[127:64] := a[63:0]
 IF (imm8[1] == 1) dst[127:64] := a[127:64]
 IF (imm8[2] == 0) dst[191:128] := a[191:128]
 IF (imm8[2] == 1) dst[191:128] := a[255:192]
 IF (imm8[3] == 0) dst[255:192] := a[191:128]
 IF (imm8[3] == 1) dst[255:192] := a[255:192]
 基本原理就是两个数为一组，00,01,10,11分别代表这两个数交换、保持不变或者前一个覆盖后一个，后一个覆盖前一个。

前面已经提到了，我们需要一个只包含z1实部的__m256d变量和一个只包含z1虚部的__m256d变量。

这里令imm8=15即可完成由虚部覆盖实部的替换，而实部覆盖虚部可以通过令imm8=0来实现，不过这里用_mm256_movedup_pd函数也可以达到相同的效果(这里吐槽一下，在SSE3中，通过_mm_moveldup_ps可以直接完成4个单精度数中由奇数下标覆盖偶数下标的操作，但是这个指令只有操作4个单精度浮点数才有，其他情况都只支持偶数下标覆盖奇数下标，反过来就不支持，难道4个单精度浮点数操作在硬件实现上有优势？)这样我们就可以得到相应的只包含实部和只包含虚部的_mm256d变量

接下来令imm8=10即可将z2中的两个复数的实部和虚部调转，这样就成功得到了计算需要的四个_mm256d变量，然后就可以计算了。

FMA乘加融合可以一次性完成a * b + c的操作，这一指令相对于分开计算拥有更快的速度和更高的精度，同时在immintrin.h中还提供了_mm256_fmaddsub_pd可以完成对偶数下标位相加，奇数下标位相减的操作。

具体的实现如下：



```cpp
void mul(complex<double> *x,complex<double> *y){
    __m256d tx,ty,r;
    tx=_mm256_loadu_pd((double*)(x));
    ty=_mm256_loadu_pd((double*)(y));
    r=_mm256_permute_pd(ty,5)*_mm256_permute_pd(tx,15);
    _mm256_storeu_pd((double*)(x),_mm256_fmaddsub_pd(ty,_mm256_movedup_pd(tx),r));
}
```

接下来测试一下效率



```cpp
#define N 10000
int main(){
    complex<double> x[2],y[2];
    x[0]=complex<double>(1,0);
    x[1]=complex<double>(-1,0);
    y[0]=complex<double>(0,1);
    y[1]=complex<double>(0,-1);
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            mul(x,y);  
        }
    }
    cout<<x[0]<<'\t'<<x[1]<<endl;  
    return 0;
}
```

使用g++ -O3优化，直接用标准库中重载的 * 进行相乘用时为：



```css
(1,-0)  (-1,-0)

real    0m0.714s
user    0m0.714s
sys     0m0.000s
```

使用SIMD加速之后的mul函数的用时为：



```css
(1,-0)  (-1,-0)

real    0m0.489s
user    0m0.485s
sys     0m0.004s
```

可以看到使用SIMD加速之后复数计算的效率有了明显的提高，因此也从侧面说明对于数组相加的那个例子，由于计算简单，编译器早已做了相应的SIMD加速，自己去写相应的操作并不能使速度加快。

### 2.3矩阵转置

最近测试了一下用SIMD实现矩阵转置法现加速效果不错
 这里先说一下算法，利用AVX指令集可以一次操作4个双精度浮点数，因此通过读取四个__m256d的数据，一次做一个4x4的方阵转置，而对于大于4x4的方阵则可以先完成每一个小块的转置，再把子块的位置进行转置，对于非原址的转置，直接把转置完的子块写到对应的位置就可以了。

以4x4矩阵为例，假设原始矩阵是
 a0,a1,a2,a3
 b0,b1,b2,b3
 c0,c1,c2,c3
 d0,d1,d2,d3
 转置完成后就应该是
 a0,b0,c0,d0
 a1,b1,c1,d1
 a2,b2,c2,d2
 a3,b3,c3,d3

这里我们需要用到AVX和AVX2指令集中_mm256_unpacklo_pd、_mm256_unpackhi_pd、 _mm256_permute4x64_pd、 _mm256_blend_pd四个操作。

_mm256_unpacklo_pd接受两个__m256d参数，并且将两个传入的参数中的第一、第三个数按顺序组成新的__m256d返回，例如当传入a0,a1,a2,a3和b0,b1,b2,b3时，则返回a0,b0,a2,b2

_mm256_unpackhi_pd与_mm256_unpacklo_pd基本相似，只不过是取得传入值的第二、第四个数组合返回

_mm256_permute4x64_pd接受一个__m256d参数和一个8位二进制数，8位二进制数每两个一组根据其在相应的8位二进制数中的位置，将传入的__m256d的第几位赋到返回的__m256d的第几位，例如传入a0,a1,a2,a3和0b11100100(转换为四个十进制数是3,2,1,0)，那么返回的值就是a3,a2,a1,a0，这里需要注意一点是寄存器中的数据排列问题，如果我们要倒置内存中的整个序列实际上应该给的二进制数是0b00011011

_mm256_blend_pd接受两个__m256d参数a和b，和一个四位二进制数，根据二进制数中每一位是1还是0，确定生成的新的__m256d对应位置是取a的值还是b的值，例如传入a0,a1,a2,a3和b0,b1,b2,b3和0b0101则生成的数据应该a0,b1,a2,b3，同样这里也需要注意寄存器中数据的排列。

有了这四个函数我们就可以设计转置的算法了，首先我们倒过来推
 要得到a0,b0,c0,d0和a1,b1,c1,d1
 我们考虑使用_mm256_unpacklo_pd和_mm256_unpackhi_pd同时生成两个转置后的序列
 那么我们就应该有a0,a1,c0,c1和b0,b1,d0,d1
 我们发现a0,a1,c0,c1而可以将a0,a1,a2,a3和c2,c3,c0,c1通过_mm256_blend_pd生成
 而a0,a1,a2,a3就是原始序列，c2,c3,c0,c1可以通过_mm256_permute4x64_pd来对c0,c1,c2,c3重排得到，而b0,b1,d0,d1也可以用同样的方法得到。通过这样重排、混洗我们就可以实现一个4x4的矩阵转置，具体的代码如下:



```cpp
            double* x=(double*)_mm_malloc(sizeof(double)*4*4,32);
            double* y=(double*)_mm_malloc(sizeof(double)*4*4,32);
            double *p1=x,*p2=x+4,*p3=x+8,*p4=x+12;
            double *d1=x,*d2=x+4,*d3=x+8,*d4=x+12,
            int k=0;    
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    x[k++]=i;
                }
            }
            __m256d s1,s2,s3,s4,t1,t2,t3,t4,t5,t6,t7,t8;
            s1=_mm256_load_pd(p1);
            s2=_mm256_load_pd(p2);
            s3=_mm256_load_pd(p3);
            s4=_mm256_load_pd(p4);
            t1=_mm256_permute4x64_pd(s1,0b01001110);//先对四个序列进行重排，把前两位和后两位调换a2,a3,a0,a1
            t2=_mm256_permute4x64_pd(s2,0b01001110);//b2,b3,b0,b1
            t3=_mm256_permute4x64_pd(s3,0b01001110);//c2,c3,c0,c1
            t4=_mm256_permute4x64_pd(s4,0b01001110);//d2,d3,d0,d1
            t5=_mm256_blend_pd(s1,t3,0b1100);//将一个调换过的序列和一个原序列进行合并用以完成最后一步混洗a0,a1,c0,c1
            t6=_mm256_blend_pd(s2,t4,0b1100);//b0,b1,d0,d1
            t7=_mm256_blend_pd(t1,s3,0b1100);//a2,a3,c2,c3
            t8=_mm256_blend_pd(t2,s4,0b1100);//b2,b3,d2,d3
            s1=_mm256_unpacklo_pd(t5,t6);//将合并的序列进行混洗，得到转置序列a0,b0,c0,d0
            s2=_mm256_unpackhi_pd(t5,t6);//a1,b1,c1,d1
            s3=_mm256_unpacklo_pd(t7,t8);
            s4=_mm256_unpackhi_pd(t7,t8);
            _mm256_store_pd(d1,s1);
            _mm256_store_pd(d2,s2);
            _mm256_store_pd(d3,s3);
            _mm256_store_pd(d4,s4);
            k=0
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    cout<<y[k++]<<'\t';
                }
                cout<<'\n';
            }
```

这样就完成了4x4的矩阵转置，接下来就是进行大规模矩阵转置测试一下性能了，以4096的方阵为例，SIMD的转置代码如下:



```cpp
#include <immintrin.h>
#include <iostream>
using namespace std;
#define N 4096
int main()
{
    double* x=(double*)_mm_malloc(sizeof(double)*N*N,32);
    double* y=(double*)_mm_malloc(sizeof(double)*N*N,32);
    int k=0;    
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            x[k++]=i;
        }
    }
    double *p1,*p2,*p3,*p4;
    double *d1,*d2,*d3,*d4,*t=y;
    d1=y;d2=y+N;d3=y+2*N;d4=y+3*N;
    p1=x;p2=x+N;p3=x+2*N;p4=x+3*N;
    t+=4;
    for(int i=0;i<N/4;i++)
    {
        for(int j=0;j<N/4;j++)
        {
            __m256d s1,s2,s3,s4,t1,t2,t3,t4,t5,t6,t7,t8;
            s1=_mm256_load_pd(p1);
            s2=_mm256_load_pd(p2);
            s3=_mm256_load_pd(p3);
            s4=_mm256_load_pd(p4);
            t1=_mm256_permute4x64_pd(s1,0b01001110);
            t2=_mm256_permute4x64_pd(s2,0b01001110);
            t3=_mm256_permute4x64_pd(s3,0b01001110);
            t4=_mm256_permute4x64_pd(s4,0b01001110);
            t5=_mm256_blend_pd(s1,t3,0b1100);
            t6=_mm256_blend_pd(s2,t4,0b1100);
            t7=_mm256_blend_pd(t1,s3,0b1100);
            t8=_mm256_blend_pd(t2,s4,0b1100);
            s1=_mm256_unpacklo_pd(t5,t6);
            s2=_mm256_unpackhi_pd(t5,t6);
            s3=_mm256_unpacklo_pd(t7,t8);
            s4=_mm256_unpackhi_pd(t7,t8);
            _mm256_store_pd(d1,s1);
            _mm256_store_pd(d2,s2);
            _mm256_store_pd(d3,s3);
            _mm256_store_pd(d4,s4);
            p1+=4;p2+=4;p3+=4;p4+=4;
            d1+=4*N;d2+=4*N;d3+=4*N;d4+=4*N;
        }
        p1+=3*N;p2+=3*N;p3+=3*N;p4+=3*N;
        d1=t;d2=t+N;d3=t+2*N;d4=t+3*N;
        t+=4;
    } 
    cout<<y[100]<<'\n';
    /*
    k=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<y[k++]<<'\t';
        }
        cout<<'\n';
    }
    */   
    return 0;
}
```

而原始代码如下：



```cpp
#include <immintrin.h>
#include <iostream>
using namespace std;
#define N 4096
int main()
{
    double* x=(double*)_mm_malloc(sizeof(double)*N*N,32);
    double* y=(double*)_mm_malloc(sizeof(double)*N*N,32);
    int k=0;    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            x[k++]=i;
        }
    }
    double *s=x,*d=y,*t=y;
    t++;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            *d=*(x++);
            d+=N;
        }
        d=t;
        t++;    
    }
cout<<y[100]<<'\n';
/*
    k=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<y[k++]<<'\t';
        }
        cout<<'\n';
    }
*/   
    return 0;
}
```

测试均使用-O2优化编译，最终测试结果如下：
 未使用SIMD



```css
real    0m0.453s
user    0m0.393s
sys     0m0.061s
```

使用SIMD



```css
real    0m0.147s
user    0m0.087s
sys     0m0.060s
```

可以看到通过SIMD加速，4096的方阵转置的性能提高了将近3倍。

### 2.4线性同余生成伪随机数

最近需要用SIMD做一个随机数生成器，本来以为很容易的，结果发现AVX的整型运算全是坑，折腾了一天可算做出来一个生成-1到1均匀分布的双精度浮点数生成器。

线性同余就不多说了，利用seed=(seed∗a+c) mod m seed=(seed*a+c)\ mod\ mseed=(seed∗a+c) mod m不断更新种子就可以得到0到m-1的均匀分布的伪随机数了。这里取m=232−1,a=513,c=9973 m=2^{32}-1,a=513,c=9973m=2
 32
 −1,a=513,c=9973

因为之前都是处理的浮点数，计算没有什么特别奇怪的地方，本以为整型也就照着写就好了。结果发现一通写之后，结果差了十万八千里。首先对于整型AVX-512才开始支持类似浮点型的load、store指令(函数)，但是我又没有支持AVX-512的机器。要用AVX读写整型需要使用mask_load和mask_store，这两个函数除了正常laod和store需要的地址和ymm寄存器变量以外，还需要一个额外的mask参数，用来控制哪些位置的整型数据读写，哪些位置不读写直接置零。这个mask也是个ymm寄存器变量，按照mask参数中各个位置数字的最高位是1还是0来决定是不是对数据进行读写。这就意味着相应位置给负数则读写相应位置，给0或者整数都会直接对相应位置置零。所以如果要将1,2,3,4四个种子读进去需要按照如下操作进行。



```cpp
unsigned t[8]={1,1,2,2,3,3,4,4};
__m256i k=_mm256_maskload_epi32((int*)t,_mm256_set1_epi32(-1));
```

读完种子下一步就可以用线性同余生成随机数了。AVX的整型乘法函数只有两个_mm256_mul_epu32和_mm256_mul_epi32，i表示有符号，u表示无符号，其他的没区别，这个乘法并不是把__m256i中的8个int或者unsigned int对应相乘，而是把数据看成4个无符号整型，然后把高位截断，只留下低32位进行相乘，然后返回存有4个64位的有符号或者无符号整型的__m256i。不过这里问题不大，也就是少生成4个随机数罢了，计算得到结果可以不同做任何修改继续计算新的随机数。



```cpp
void Rand(__m256i &seed)
{
    seed=_mm256_mul_epu32(seed,_mm256_set1_epi32(513));
    seed=_mm256_add_epi64(seed,_mm256_set1_epi64x(9973));
    seed=_mm256_and_si256(seed,_mm256_set1_epi64x(4294967295));
}
```

其实如果单纯只是需要无符号整型随机数这个函数就够了。但是由于我需要的是一个-1到1均匀分布的浮点数，所以这个结果还要进一步处理。然而4个无符号的___m256i转到__m256d的函数需要AVX512的支持，而4个64位无符号__m256i转成4个无符号的__m128i的函数完全找不到。但是在cast函数中有一个强制转换__m256i到__m128i的函数，这个函数直接强制截断一半__m256i生成新的__m128i。但是由于seed中如果看做8个32位整数，则我们生成的随机数是在0,2,4,6四个位置上的，直接截断就只剩两个数了。这就需要对数据进行重排，然后又要使用permute函数了。这里使用_mm256_permutevar8x32_epi32函数进行重排，这个函数很好用，确定每个位置放置哪个原始位置的数是通过__m256i变量来确定的，直接给一个__mm256_set_epi32(p1,p2,…,p8)就行了(p1,p2,…,p8就是对应位置上需要放置的数据编号，例如要倒置就是7,6,5,4,3,2,1,0这里注意大端小端的问题，具体是多少需要测试，这里只是示意)。这样就可以把四个随机数集中到前面128位了，然后直接截断就可以得到包含4个32位整型的__m128i变量。然后这个变量可以通过cvt转换成包含4个双精度的__m256d变量，再做一次除法即可生成4个-1到1均匀分布的双精度浮点数(这里双精度只是数据类型，实际随机数的精度只有1/232 {1}/{2^{32}}1/2
 32
 )。这里需要注意的是这个转换双精度浮点数是按有符号读取的，因此化为-1到1时除掉的整数，是Rand函数中m值的一半。



```undefined
Rand(k);
__m256i rd=_mm256_permutevar8x32_epi32(k,_mm256_set_epi32(0,0,0,0,0,2,4,6));
__m128i rrd=_mm256_castsi256_si128 (rd);
__m256d u=_mm256_cvtepi32_pd(rrd);
_mm256_storeu_pd(x,u/_mm256_set1_pd(4294967295));
```

完整的代码如下



```cpp
#include <iostream>
#include <immintrin.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void Rand(__m256i &seed)
{
    seed=_mm256_mul_epu32(seed,_mm256_set1_epi32(513));
    seed=_mm256_add_epi64(seed,_mm256_set1_epi64x(9973));
    seed=_mm256_and_si256(seed,_mm256_set1_epi64x(4294967295));
}
int main()
{
    unsigned t[8]={1,1,2,2,3,3,4,4},tj[16]={};
    double x[4];
    __m256i k=_mm256_maskload_epi32((int*)t,_mm256_set1_epi32(1));
    auto s=clock(); 
    for(int i=0;i<10000;i++)
    {
        Rand(k);
        __m256i rd=_mm256_permutevar8x32_epi32(k,_mm256_set_epi32(0,0,0,0,0,2,4,6));
        __m128i rrd=_mm256_castsi256_si128 (rd);
        __m256d u=_mm256_cvtepi32_pd(rrd);
        _mm256_storeu_pd(x,u/_mm256_set1_pd(2147483647));
        for(int j=0;j<4;j+=1) 
        {
            cout<<x[j]<<'\t';
            //tj[int(x[j]*8+8)]++;
        }
        cout<<'\n';
    }
    auto e=clock();
    for(int i=0;i<40000;i++) 
    {   for(int j=0;j<4;j++)cout<<double(rand())/RAND_MAX<<'\t';
        cout<<'\n';
    }
    auto e1=clock();
    cout<<"time = "<<double(e-s)/CLOCKS_PER_SEC<<'\t'<<double(e1-e)/CLOCKS_PER_SEC;
    for(int i=0;i<16;i++) cout<<tj[i]<<'\n';
    return 0;
}
```

这里用tj做一个了统计，测试生成的随机数是不是均匀分布的，然后还和用标准库的rand函数生成相同数量的随机数用时的差距。

单独进行统计得到的结果如下



```undefined
2588
2532
2536
2448
2592
2416
2572
2788
2688
2420
2420
2396
2356
2356
2668
```

可以看到把-1到1均分为16份对40000个样本进行统计，落在各个区间的随机数的个数基本在2500附近，证明这个计算过程没有太大问题。

然后看一下效率，由于不打印到控制台，开了优化之后计算过程会被直接优化掉，而打印到控制台，打印又异常耗时，这里就简单测一下。把输出结果直接重定向到文件中，这样输出的时间会短一些，对结果的影响稍小。使用gcc的O3优化，用时统计如下



```css
0.020918s(使用AVX)
0.0904440s(标准库rand函数)
```

可以看到使用AVX之后生成随机数的速度明显变快了。