/*********************************************
| 判断点q 是否在多边形内
其中多边形是任意的凸或凹多边形，
Polygon中存放多边形的逆时针顶点序列
*********************************************/
int pinplg(int vcount,Lpoint Polygon[],Lpoint q)
{
    int c=0,i,n;
    Llineseg l1,l2;
    l1.a=q;
    l1.b=q;
    l1.b.x=infinity;
    n=vcount;
    for (i=0; i<vcount; i++)
    {
        l2.a=Polygon[i];
        l2.b=Polygon[(i+1)%n];
        if ((lsinterls_A(l1,l2))||
                (
                    (ponls(l1,Polygon[(i+1)%n]))&&
                    (
                        (!ponls(l1,Polygon[(i+2)%n]))&&
                        (xmulti(Polygon[i],Polygon[(i+1)%n],l1.a) *
                         xmulti(Polygon[(i+1)%n],Polygon[(i+2)%n],l1.a)>0)
                        ||
                        (ponls(l1,Polygon[(i+2)%n]))&&
                        (xmulti(Polygon[i],Polygon[(i+2)%n],l1.a) *
                         xmulti(Polygon[(i+2)%n],Polygon[(i+3)%n],l1.a)>0)
                    ) ) ) c++;
    }
    return(c%2!=0);
}
