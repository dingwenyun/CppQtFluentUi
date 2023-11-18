QRect adjusted及adjust

>void adjust(dx1,dy1,dx2,dy2)
>
>> 修改这个变量本身
>
>QRect adjusted(dx1,dy1,dx2,dy2)
>
>> 不修改变量本身，而是返回一个调整过后的QRect
>
>例子
>
>> dx1,dy1调整矩形左上角点位置
>> dx2,dy2调整矩形右下角点位置
>> QRect rect1 = QRect(0,0,10,20);
>> rect1.adjust(5,5,-1,-2);//rect1的区域(5,5,9,18)
>> auto rect2 = rect1.adjusted(-2,-1,5,-3);//rect1依然为(5,5,9,18) rect2为(3,4,14,15)