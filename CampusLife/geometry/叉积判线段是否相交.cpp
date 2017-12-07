using namespace std;
const int maxn=100000;

struct point{
    double x,y;
    void read(){
        cin>>x>>y;
    }
}p[33];

struct line{
    point st, en;
    line(point s,point e) : st(s),en(e){}
};

double cross(point p0,point p1,point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int work(line h,line g){
    double x = cross(h.st,h.en,g.st);
    double y = cross(h.st,h.en,g.en);
    if(x*y<=0) return 1;
    return 0;
}

inline bool OK(int i,int j,int k,int l)
{
    line l1(p[i],p[j]);
    line l2(p[k],p[l]);
    if(work(l1,l2) && work(l2,l1)) return 1;
    return 0;
}
