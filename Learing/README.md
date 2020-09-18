# C++学习笔记

## 设计Class所需要注意的点

1. 构造函数利用好initialization
2. 传参或者返回时，尽量by reference而不是by value
   1. 设计+=时的例子

    ```C++
    /*  ths和r相加后要放在ths里面 因此r是const by reference
        而ths不能const  */
    __doapl(complex* ths, const complex& r)
    {
        ths->re += r.re;    //第一参数将会被改动
        ths->im += r.im;    //第二参数不会被改动
        return *thm;
    }
    ```

3. 应该加const就要加，如果不加,使用时可能会报错
4. 数据一定放在private里面

---

## 操作符重载(operator overloading)

```C++
inline complex&
complex::operator += (const complex& r)
{
  return __doapl (this, r);
  //this是指左边的值,r是指右边的值,传入参数时不用写this
}
```

### return by value or return by reference

```C++
inline complex&     //return by reference
complex::operator *= (const complex& r)
{
  return __doaml (this, r);
  //return的是一个对象,即值已经在对象中了,函数执行完以后还存在
}

inline complex      //return by value
operator + (const complex& x, const complex& y)
{
  return complex (real (x) + real (y), imag (x) + imag (y));
  //return的不是一个对象,即值还没放在对象中
  //这个return的东西在函数执行完以后就不存在了,因此如果引用是野指针
}
```

## 临时对象(temp object)

### typename()

```C++
inline complex
operator + (const complex& x, double y)
{
  return complex (real (x) + y, imag (x));
  //complex 直接加小括号,创建临时对象,生命到下一行就结束了
}
```
