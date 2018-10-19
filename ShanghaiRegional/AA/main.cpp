#include <bits/stdc++.h>
using namespace std;
#define maxn 100005

const double eps = 1e-5;
const double INF = 1e20;
const double pi = acos (-1.0);

int dcmp (double x) {
    if (fabs (x) < eps) return 0;
    return (x < 0 ? -1 : 1);
}
//*************��
struct Point {
    double x, y;
    Point (double _x = 0, double _y = 0):x(_x), y(_y) {}
    bool operator < (const Point &b) const {
        return (dcmp (x-b.x) == 0 ? dcmp (y-b.y) < 0 : x < b.x);
    }
    Point operator + (const Point &b) const {
        return Point (x+b.x, y+b.y);
    }
    Point operator - (const Point &b) const {
        return Point (x-b.x, y-b.y);
    }
    Point operator * (double a) {
        return Point (x*a, y*a);
    }
    Point operator / (double a) {
        return Point (x/a, y/a);
    }
    double len2 () {//���س��ȵ�ƽ��
        return x*x + y*y;
    }
    double len () {//���س���
        return sqrt (len2 ());
    }
    Point change_len (double r) {//ת��Ϊ����Ϊr������
        double l = len ();
        if (dcmp (l) == 0) return *this;//��������������
        r /= l;
        return Point (x*r, y*r);
    }
};

//�������������Ĳ��
long double cross(const Point &a,const Point &b){
    return a.x*b.y-a.y*b.x;
}
//����������ĵ��
long double dot(const Point &a,const Point &b){
    return a.x*b.x+a.y*b.y;
}

long double xmult(Point p0,Point p1,Point p2) {
    return cross((p1-p0),(p2-p0));
}
//dot(p1-p0).(p2-p0)
long double dmult(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
long double dis (Point a, Point b) {//������ľ���

    Point p = b-a; return p.len ();
}

//************ֱ�� �߶�
struct Line {
    Point s, e;//ֱ�ߵ�������
    double k;//����
    Line () {}
    Line (Point _s, Point _e) {
        s = _s, e = _e;
        k = atan2 (e.y - s.y,e.x - s.x);
    }
    double length () {//���߶γ���
        return dis (s, e);
    }
};
//���ֱ�ߵĹ�ϵ
int relation (Point p, Line l) {
    //1:����� 2:���Ҳ� 3:��ֱ����
    int c = dcmp (cross (p-l.s, l.e-l.s));
    if (c < 0) return 1;
    else if (c > 0) return 2;
    else return 3;
}
//�жϵ����߶���
bool point_on_seg (Point p, Line l) {
    return dcmp (cross (p-l.s, l.e-l.s)) == 0 &&
    dcmp (dot (p-l.s, p-l.e) <= 0);
    //������Զ˵㽻��ĳ�С�ںžͺ���
}
//�жϵ���������
bool point_on_halfline (Point p, Line l) {
    int id = relation (p, l);
    if (id != 3) return 0;
    return dcmp (dot (p-l.s, l.e-l.s)) >= 0;
}
//�㵽ֱ�ߵľ���
double point_to_line (Point p, Line a) {
    return fabs (cross (p-a.s, a.e-a.s) / a.length ());
}
//����ֱ���ϵ�ͶӰ
Point projection (Point p, Line a) {
    return a.s + (((a.e-a.s) * dot (a.e-a.s, p-a.s)) / (a.e-a.s).len2() );
}
//�����ֱ�ߵĶԳƵ�
Point symmetry (Point p, Line a) {
    Point q = projection (p, a);
    return Point (2*q.x-p.x, 2*q.y-p.y);
}
//***************Բ
struct Circle {
    //Բ�� �뾶
    Point p;
    double r;
    Circle () {}
    Circle (Point _p, double _r) : p(_p), r(_r) {}
};
//ֱ�ߺ�Բ�Ĺ�ϵ
int relation (Line a, Circle b) {
    //0:���� 1:���� 2:�ཻ
    double p = point_to_line (b.p, a);
    if (dcmp (p-b.r) == 0) return 1;
    return (dcmp (p-b.r) < 0 ? 2 : 0);
}
//ֱ�ߺ�Բ�Ľ���
int line_circle_intersection (Line v, Circle u, Point &p1, Point &p2) {
    //���ؽ������ ���㱣����������
    if (!relation (v, u)) return 0;
    Point a = projection (u.p, v);
    double d = point_to_line (u.p, v);
    d = sqrt (u.r*u.r - d*d);
    if (dcmp (d) == 0) {
        p1 = a, p2 = a;
        return 1;
    }
    p1 = a + (v.e-v.s).change_len (d);
    p2 = a - (v.e-v.s).change_len (d);
    return 2;
}
Circle c;
Point A,B;
long double v1,v2;

int main(){
    freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>c.p.x>>c.p.y>>c.r;
        cin>>A.x>>A.y>>v1>>v2;
        cin>>B.x>>B.y;

        cout<<"Case #"<<cas<<": ";
        Point temp=Point(A.x+v1,A.y+v2);
        int num;
        Point p1,p2;
        num=line_circle_intersection(Line(A,temp),c,p1,p2);
        if(num<2){
            if(dmult(A,temp,B)>eps&&fabs(xmult(A,temp,B))<eps) cout<<"Yes"<<endl;
            //if(point_on_halfline(B,Line(A,temp))) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else{       //�ཻ
            Point L;
            if(dis(A,p1)>dis(A,p2)) L=p2;
            else L=p1;
            //if(point_on_seg(B,Line(A,L))){
            if(abs(xmult(B,A,L))<eps&&dmult(B,A,L)<-eps){
                cout<<"Yes"<<endl;
                continue;
            }
            Point B2=symmetry(A,Line(L,c.p));
            //if(point_on_halfline(B,Line(L,B2))) cout<<"Yes"<<endl;
            if(abs(xmult(L,B2,B))<eps&&dmult(L,B2,B)>eps) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
