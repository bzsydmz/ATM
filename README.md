# ATM
ATM模拟

（大一上学期期末的project作业）

1.需求分析

（1）用户信息，需存入数据文件中。
（2）ATM机的主要功能：查询余额、存款、取款、转账、修改密码、退卡。
（3）具体需求：
  数据文件的读和写。
  打印ATM机的模拟形状。
  欢迎界面，在程序运行时首先显示。
  输入账号密码进行登录。
  登录时验证账号密码正确性，若连续输入错误三次，锁卡并显示锁卡提示。
  登录成功后显示主功能界面，可用数字1到6选择要办理的业务。
  查询余额：显示账户余额。
  取款：有默认可选择的取款金额和可输入的其他数额，若出现余额不足、超出单次或单日取款上限、取款数额不是100整数倍的情况给予相应提示，未出现这类情况即成功取款，将用户余额及单  日取款金额做出相应更改，并写入数据文件。
  存款：直接输入存款金额，其他与取款功能类似。
  转账：输入转入者账户，在数据文件中查找此账户，根据输入的转账金额对当前用户和目标用户的账户余额做相应更改，并更改当前用户的当日取款金额。
  单日存取上限：每次进行存取款及转账时更改用户数据并写入数据文件。并判断数据文件中储存的记录是否已过期。
  
2.系统设计

（1）面向对象设计，实现良好封装性。
  设计User类，包含各类用户数据，包括：账号、密码、姓名、身份证号、账户余额、单日存取款金额、存取款时间。
	设计ATM类，包含ATM机的各项功能。
（2）数据文件读写
  设计createAccount函数，程序运行时，若未找到数据文件，会自动生成记录用户数据的文本文件。数据文件记录了四个用户数据，初始文件内容如下：
  
    111111111111111111111111134512320011211132410000000000000018993sandy
    123456789012345678912345610000019701111212110000000000000018993joker
    121212121212121212112121223021219901211111110000000000000018993hutao
    109123771012938109247798550922220000302897810000000000000018993luban
    
  每行依次为账号、密码、身份证号、账户余额、存款记录、取款记录、存取款时间（随文件生成时日期不同而不同）、姓名。
  读文件时，使用函数readFile返回string地址类型。使用getline函数读入四个字符串，使用substr函数很好地得到各项数据，因为姓名的字符长度不定，故放在最后，使用substr函数从姓名第一个字符截取到字符串末尾。
  写文件时，使用函数writeFile写回改变的数据，对改变的数据以外的数据原样写回。
（3）其他功能设计
  设计用于实现输入效果的函数inputNumber及inputPassword。输入账号密码及金额时只能输入数字，且有位数限制。输入密码时界面显示星号而不显示相应数字，且保证输入六位才能选择确认。
  设计loading函数，实现“加载中”效果。
  设计numFarmat函数，实现显示金额时每三位数字用一个逗号分隔，且保留为两位小数的效果。
  设计refreshRecord函数，利用time函数获取当前日期，程序每次运行时对照当前日期与数据文件中记录的日期是否相同，选择是否清空存取款记录。
  设计moveCursor函数，实现对光标的移动，便于操作。
  设计hideCursor函数，隐藏控制台光标闪烁，提高美观性。
  
3.系统实现

  四个账户的账号密码依次为：
  
  用户一：1111111111111111111 111111
  用户二：1234567890123456789 123456
  用户三：1212121212121212121 121212
  用户四：1091237710129381092 477985
  
  程序运行时显示欢迎界面，插卡后输入账号密码并验证，为保证ATM账户安全性，不支持复制粘贴（意思是要麻烦老师一个一个自己输了）
  输入正确后进入主页面。

  根据提示选择相应操作办理相应业务。
  
4.总结

  ATM模拟程序复杂度较高，利用面向对象设计能够实现较好的封装性和代码的复用性。
