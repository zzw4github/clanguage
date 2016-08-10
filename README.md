### clanguage

[c-tutorial](http://www.cprogramming.com/tutorial/c-tutorial.html "c-tutorial")

[cprogramming](http://www.tutorialspoint.com/cprogramming/ "cprogramming")

[learn-c](http://www.learn-c.org/ "learn-c")


###STL
[cppreference_en](http://en.cppreference.com/w/cpp)  
[cppreference_zh](http://zh.cppreference.com/w/cpp)    
[sgi_stl](http://www.sgi.com/tech/stl/)  

###book
(book_list)[http://stackoverflow.com/questions/388242/the-definitive-c-book-guide-and-list]

##sublime build
[配置gcc](http://www.yalewoo.com/sublime_text_3_gcc.html)

1. mingw 配置环境变量 
2. 选择tool –> Build System –> New Build System
3. 输入下面代码
```
{
	"working_dir": "$file_path",
	"cmd": "gcc -Wall \"$file_name\" -o \"$file_base_name\"",
	"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
	"selector": "source.c",
 
	"variants": 
	[
		{	
		"name": "Run",
        	"shell_cmd": "gcc -Wall \"$file\" -o \"$file_base_name\" && start cmd /c \"\"${file_path}/${file_base_name}\" & pause\""
		}
	]
}
```
4. 按Ctrl+s保存，会自动打开user目录（Sublime Text 3\Packages\User），我们修改 文件名为 c.sublime-build，保存在此目录。
5. ctrl+b ctrl+shif+b 编译 运行

