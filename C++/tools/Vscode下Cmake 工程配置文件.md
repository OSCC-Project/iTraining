Vscode下Cmake 工程配置文件

1 下载扩展cmake 与cmake tools
2  编写 .vscode下的launch.json

 以我为例子
		

```c++
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/run_dr",//你的cmake编译后的输出可执行文件的位置
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
        }
    ]
}

```



3 编写你的task.json 用于自动cmake 和make

```c++
{
    "version":"2.0.0",
    "options": {
        "cwd": "${workspaceRoot}/build" //执行命令的目录
    },
    "tasks":[
        {
            "label": "cmake",
            "type": "shell",
            "command": "cmake",
            "args": [
                ".."
            ],
        },
        {
            "label": "make",/////////要执行的第二个make命令
            "type": "shell",
            "command": "make",
            "args": [],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "dependsOn":["cmake"],///指定，在执行make之前，需先执行cmake
        },
    ]
}

```

成功之后应该 ![image-20210618211829080](C:\Users\mo\AppData\Roaming\Typora\typora-user-images\image-20210618211829080.png)

注意.vsocde文件应该在你的工程项目内