#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double dis_cal(double a, double d, int b, int c)
{
    double dist;
    dist = sqrt(((a - b) * (a - b)) + ((d - c) * (d - c)));
    return 0;
}
double time_cal(double point, double f, int x_l, int y_l, int x_w, int y_w)
{
    double run, swim;
    run = dis_cal(point, 0, x_l, y_l);
    swim = dis_cal(point, 0, x_w, y_w);
    run /= f;
    return run + swim;
}
int main()
{
    int x_l, y_l, x_w, y_w;
    double f;
    cin>>x_>>y_l>>x_w>>y_w>>f;
    double right = (x_l > x_w) ? x_l : x_w;
    double left = (x_l < x_w) ? x_l : x_w;
    double mid, curr_time, next_time, prev_time;
    while (1)
    {
        mid = (left + right) / 2;
        curr_time = time_cal(mid, f, x_l, y_l, x_w, y_w);
        next_time = time_cal(mid + 0.000001, f, x_l, y_l, x_w, y_w);
        prev_time = time_cal(mid - 0.000001, f, x_l, y_l, x_w, y_w);
        cout<<1;
        if (curr_time > prev_time)
            right = mid - 0.000001;
        else if (curr_time > next_time)
            left = mid + 0.000001;
        else
            break;
    }
    printf("%lf", mid);
    return 0;
}