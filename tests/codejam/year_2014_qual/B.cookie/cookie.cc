#include <stdio.h>
#include <limits.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#include <math.h>

//#define DBG

using namespace std;

static double cookies = 0;
static double speed = 2;

static long farms = 0;

static double C;
static double F;
static double X;

static double T;

int main()
{
  int v;

  int tc;
  v = scanf("%d",&tc);

  int tt = 1;
  while(tc) {

    cookies = 0.0;
    speed = 2.0;

    farms = 0;

    T = 0.0;

    v = scanf("%lf %lf %lf",&C,&F,&X);
        
    //    printf("%.7lf %.7lf %.7lf\n", C,F,X);

    // C = farm cost cookies
    // F = farm extra speed cookies
    // X = goal nbr cookies
    

    while (cookies < X) {

      //      printf("time %lf cookies %lf speed %lf (C %lf F %lf X %lf)\n", T, cookies, speed, C, F, X);

      if (cookies >= C) {

        // t_farm = 0;

        double c_left = (X - cookies);
        double t_left_cur_speed = (c_left / speed);
        
        double c_left_plus_farm = (X - (cookies - C));
        double speed_plus_farm = speed + F;
        double t_left_plus_farm = (c_left_plus_farm / speed_plus_farm);

        //        printf("t_left %lf t_plus_farm %lf\n", t_left_cur_speed, t_left_plus_farm);

        // should we buy farm?
        if (t_left_cur_speed > t_left_plus_farm) {

          // buy farm
          //    printf("Buy!\n");
          cookies -= C;
          speed += F;
        }
        else {
          // dont buy
          cookies += (t_left_cur_speed * speed);
          T += t_left_cur_speed;          
        }


        // at time T + t_farm, how many cookies do we have without farm / with farm?


      }
      else {
        // time to next farm with current speed
        double needed_c_buy_farm = (C - cookies);
        double t_farm = needed_c_buy_farm / speed;

        // if next_farm time exceed X, then we are done, we cannot buy farm
        double c_at_next_farm = cookies + (t_farm * speed);

        //    printf("needed_c %lf t_farm %lf c_next %lf\n", needed_c_buy_farm, t_farm, c_at_next_farm);

        if (c_at_next_farm >= X) {
          // we are done, expect current speed
          T += (X - cookies) / speed;
          cookies = X;
          continue;
        }

        // check cookies left
        double c_left = (X - cookies);
        double t_left_cur_speed = (c_left / speed);

        if (t_left_cur_speed < t_farm) {
          cookies += (t_left_cur_speed * speed);
          T += t_left_cur_speed;
        }
        else {
          // jump forward in time, check next farm possible
          cookies += (t_farm * speed);
          T += t_farm;
        }
      }






      
      
      

    }

    //----------

    printf("Case #%d: %.7lf\n", tt, T);


    tt++;
    tc--;
  }

  (void)v;
  return 0;
}
