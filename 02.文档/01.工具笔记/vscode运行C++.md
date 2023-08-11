### 目标：

1.运行cpp`<br />`2.调试cpp`<br />`3.生成的exe文件在文件根目录下的exe文件包内`<br />`4.使用git管理代码

### 一.运行cpp

---

1. 添加C/C++插件

![image.png](https://cdn.nlark.com/yuque/0/2023/png/35355517/1690534144803-73d4ee83-95b3-4b3d-ac19-d6559dd73926.png#averageHue=%23dee1ed&clientId=u079cf012-b306-4&from=paste&height=75&id=u1d0b8776&originHeight=94&originWidth=273&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=7391&status=done&style=none&taskId=ua494f96c-d7d1-41d5-9908-be09de3c1f0&title=&width=218.4)`<br />`_________________________________________________________

2. 创建一个文件夹，文件夹不能存在中文字段，用vscode打开该文件夹

---

3. 创建一个cpp文件，运行该cpp文件，当目录中出现.vscode/task.json即为成功

---

### 二.调试cpp

_________________________________________________________`<br />`焦点聚集在cpp文件

1. 点击任务栏的 运行->添加配置

选择 C++ （GDB/LLDB）`<br />`![image.png](https://cdn.nlark.com/yuque/0/2023/png/35355517/1690532904906-034572f4-3a4f-4890-983c-e60cfda2f003.png#averageHue=%23f3f2f2&clientId=u079cf012-b306-4&from=paste&height=116&id=ub1e3121b&originHeight=145&originWidth=448&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=5765&status=done&style=none&taskId=u26b05426-f79c-4dc0-a96d-ec44d5a06d4&title=&width=358.4)`<br />`_________________________________________________________

2. 添加gdb启动配置

![image.png](https://cdn.nlark.com/yuque/0/2023/png/35355517/1690534213981-36169aec-f061-4b10-9000-d6ee61ea516c.png#averageHue=%23fffff8&clientId=u079cf012-b306-4&from=paste&height=51&id=ua3cc30f7&originHeight=64&originWidth=143&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=1396&status=done&style=none&taskId=u4d71ab6b-cae0-4253-a1fb-8871affaa20&title=&width=114.4)`<br />`_________________________________________________________

3. 选择C/C++:（gdb）启动

![image.png](https://cdn.nlark.com/yuque/0/2023/png/35355517/1690534300871-d8d88e27-a4d1-41d1-85e1-6aa00221eac5.png#averageHue=%239ebad6&clientId=u079cf012-b306-4&from=paste&height=58&id=u0ed489ef&originHeight=72&originWidth=380&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=8006&status=done&style=none&taskId=u871a694b-aac1-4415-9573-6d19e0bf1bb&title=&width=304)`<br />`此时生成了launch.json文件`<br />`_________________________________________________________

4. **修改program与 miDebuggePath  **

program输入将要进行调试程序的完整路径。`<br />`miDebuggePath需要选择电脑里gdb的路径，一般保存在MinGW的[bin文件](https://so.csdn.net/so/search?q=bin%E6%96%87%E4%BB%B6&spm=1001.2101.3001.7020)夹里。`<br />`"miDebuggerPath": "D:/mingw_v8.1/mingw64/bin/gdb.exe"`<br />`![image.png](https://cdn.nlark.com/yuque/0/2023/png/35355517/1690534426957-2e07d5ec-e8ef-48c0-baad-b696d349271e.png#averageHue=%23fdfcfb&clientId=u079cf012-b306-4&from=paste&height=259&id=ubfa261be&originHeight=324&originWidth=717&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=25291&status=done&style=none&taskId=ue61928e8-cfd0-4998-b549-b667c922147&title=&width=573.6) `<br />`以上为修改成功后的文件，此时调试的文件是根目录下的exe包中的demo.exe文件，也即/exe/demo.exe。`<br />`_________________________________________________________

5. 每次调试文件时，记得更改launch.json中的program中的路径

---

### 三.生成的exe文件在文件根目录下的exe文件包内

1. **修改tasks.json文件中的args中的内容**

将路径修改为所要将exe文件放置的路径`<br />`"E:/code/VScode/DemoTest02/exe/${fileBasenameNoExtension}.exe"`<br />`![image.png](https://cdn.nlark.com/yuque/0/2023/png/35355517/1690533782597-bcaef476-2358-45d6-bfe4-c40a59d559a8.png#averageHue=%23fdfbfb&clientId=u079cf012-b306-4&from=paste&height=299&id=ubce83708&originHeight=374&originWidth=842&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=25632&status=done&style=none&taskId=u1126683d-b930-49c3-9311-81fd9ce27f7&title=&width=673.6)

### 四.使用git管理代码

1. 搜索git.path
2. <br />
