namespace SALES
{
    const int QUARTERS = 4;
    
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    // 从数组 ar 中复制最多 4 项到 s 的 sales 成员中，并计算和存储输入项目的平均值、最大值和最小值；
    // 如果 sales 中有剩余元素，则将其设置为 0
    void setSales(Sales &s, const double ar[], int n);

    // 交互式地收集 4 个季度的销售数据，存储在 s 的 sales 成员中，并计算和存储其平均值、最大值和最小值
    void setSales(Sales &s);

    // 显示结构 s 中的所有信息
    void showSales(const Sales &s);
}
