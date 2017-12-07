Node.js Q && A
===

### let与val的问题

> Q: let，val有什么区别?

> A:
> 1. 使用 let 语句声明一个变量，该变量的范围限于声明它的块中。可以在声明变量时为变量赋值，也可以稍后在脚本中给变量赋值。  
> 2. 使用 let 声明的变量，在声明前无法使用，否则将会导致错误。
> 3. 如果未在 let 语句中初始化您的变量，则将自动为其分配 JavaScript 值 undefined。
>
> 参考链接:
> * [let 语句](https://msdn.microsoft.com/library/dn263046(v=vs.94).aspx)
> * [let 语句](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/let)

### 关于this的在函数中的值的问题

> Q: 在下面这段代码中，this的值需要注意什么?
> ```
> $('#room-list div').click(function() {
>    chatApp.processCommand('/jion' + $(this).text());
> });
> ```

> A: 随着函数使用场合的不同，this的值会发生变化。但是有一个总的原则，那就是this指的是，调用函数的那个对象。
> 
> 参考链接: [廖雪峰的博客-关于this](http://www.ruanyifeng.com/blog/2010/04/using_this_keyword_in_javascript.html)

### 关于在括号里面声明的变量问题

> Q: 在括号里声明的变量不应该在括号结束之后被销毁吗, 如下代码, x在后面却还能用:
>```
> a = [1, 2, 3, 4];
> for(var x in a) {
>    var name = a[x];
> } 
> typeof name;
>```

> A: 这是因为js的作用域问题，只有当有一个function运行时，作用域栈会push这一个function的作用域，而出现{}并不代表开辟了新的作用域，而这个{}仍在这之前的作用域之下，因此，在这其中声明x和在外面声明x效果是一样的。
> 只有当新建函数之后，这个函数在被调用时会创建新的作用域，这个作用域会被加到作用域栈上。
> 当该作用域被从作用域栈上移除时，作用域内声明的属性才会被删除。