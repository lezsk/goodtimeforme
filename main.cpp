#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include <complex>
using namespace std;

const int maxn = 0x0002<<19;

void showfac(int a[maxn][3],int n){

    int tmp = a[n][0],tmp2 = a[n][1];
    int tm = abs(a[n][0]),tm2 =abs( a[n][1]);
    cout<<tmp<<"  "<<tmp2;
    // think when parameter is ordinary even number, factorize it to 2powers and odd
    if(log(tm)/log(2)-floor(log(tm)/log(2))>1e-9){cout<<endl<<endl<<tmp<<"subfactor: ";showfac(a,tm);}
    if(log(tm2)/log(2)-floor(log(tm2)/log(2))>1e-9){cout<<endl<<endl<<tmp2<<"subfactor: ";showfac(a,tm2);}

}
void check(int n){

    set<int> all;//cost 0
    set<int> cost1;
    set<int> cost2;
    set<int> cost3;
    set<int> cost4;
    set<int> cost5;
    set<int> cost6;
    set<int>::iterator it;
    int par;
    int detail[maxn][3];
    for(int i =0;i<maxn;i++){
        for(int j=0; j<3;j++)
            detail[i][j]=0;
    }


    detail[1][1]=1; detail[1][0]=0;
    // this part is cost 0 coefficient
    cost1.insert(1);
    // end part

    // this part cost 1 coefficients  cost1 are all odd number beside 2powers

    cost1.insert(1);
    for(int i = 2; i<19; i++){
        par = pow(2,i);
        if((par+1)==n)cout<<1<<" "<<pow(2,i)<<endl;
        if((par-1)==n)cout<<-1<<" "<<pow(2,i)<<endl;
        if(par<maxn-1){
            cost1.insert(pow(2,i)+1);detail[par+1][0]=1;detail[par+1][1]=pow(2,i);
            cost1.insert(pow(2,i)-1);detail[par-1][0]=-1;detail[par-1][1]=pow(2,i);
        }
    }

    //test para
    cout<<"Possible minimal cases, even numbers are sub-fundamentals"<<endl;
    cout<<"For the last case, details will be given\n";


    //this part cost 2 coefficient
    cost2 = cost1;
    all = cost1;
    //multi subpart
    for(set<int>::iterator newit = cost1.begin(); newit!=cost1.end();newit++){

        for(set<int>::iterator it2 = cost1.begin(); it2!=cost1.end();it2++){
            all = cost1;
            par = (*newit)*(*it2);

            if(par<maxn){
                cost2.insert(par);
                //if(!get<1>(all.insert(par))&par==n)cout<<*newit<<" "<<*it2<<endl;
                if((detail[par][2]==2)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if(detail[par][1]==0){ detail[par][0]=*it2;detail[par][1]=*newit;detail[par][2]=2;}

            }
        }
    }

   //end multi
   // add subpart
    for(set<int>::iterator newit = cost1.begin(); newit!=cost1.end();newit++){
        //cout<<*newit<<endl;
        for(int i =1; i<19;i++){
              //  all = cost1;
            par = (*newit)+pow(2,i);

            if((par<maxn)&((abs((*newit)-pow(2,i))<maxn))){
                cost2.insert(par);
                //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par][2]==2)&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if(detail[par][1]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par][2]=2;}

                par=abs((*newit)-pow(2,i));
                cost2.insert(abs((*newit)-pow(2,i)));
                  //if(!get<1>(all.insert(abs((*newit)-pow(2,i))))&(par==n))cout<<*newit<<" "<<-pow(2,i)<<endl;

                bool r = (*newit-pow(2,i)>0);
                if(r){  if((detail[par][2]==2)&(par==n))cout<<*newit<<" "<<-pow(2,i)<<endl;
                if(detail[par][1]==0){

                detail[par][0]=*newit;detail[par][1]=(-pow(2,i));detail[par][2]=2;}}
            else {
                 if((detail[par][2]==2)&(par==n))cout<<-*newit<<" "<<pow(2,i)<<endl;
                    if(detail[par][1]==0){
                    //if(!get<1>(all.insert(abs((*newit)-pow(2,i))))&(par==n))cout<<-*newit<<" "<<pow(2,i)<<endl;

                    detail[par][0]=-(*newit);detail[par][1]=pow(2,i);detail[par][2]=2;
                 }
            }
        }
    }
}
     for(set<int>::iterator newit = cost1.begin(); newit!=cost1.end();newit++){
        for(int i =1; i<19;i++){
            all = cost1;
            par = pow(2,i)*(*newit);

            if(par<maxn){
                if(par<maxn-1)cost2.insert(par+1);
                //  if(!get<1>(all.insert(par+1))&((par+1)==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par][2]==2)&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if(detail[par+1][1]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);
                detail[par+1][0]=par;detail[par+1][1]=1;detail[par+1][2]=2;}

                cost2.insert(par-1);
                // if(!get<1>(all.insert(par-1))&((par-1)==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par][2]==2)&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if(detail[par-1][1]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);
                detail[par-1][0]=pow(2,i)*(*newit);detail[par-1][1]=-1;detail[par-1][2]=2;}
            }
        }
    }

   //end of cost2


   //this part cost 3 coefficient

   //multi subpart
   for(set<int>::iterator newit = cost2.begin(); newit!=cost2.end();newit++){
        for(set<int>::iterator it2 = cost1.begin(); it2!=cost1.end();it2++){
            //  all = cost2;
            par = (*newit)*(*it2);
            if(par<maxn){
                cost3.insert(par);
                //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if((detail[par][2]==3)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if(detail[par][1]==0){ detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=3;}
            }
        }
   }
   //end multi
   // add part
    for(set<int>::iterator newit = cost2.begin(); newit!=cost2.end();newit++){
        for(int i =1; i<19;i++){
            //all = cost2;
            par = (*newit)+pow(2,i);

            if((par<maxn)&(abs((*newit)-pow(2,i))<maxn)){
                cost3.insert(par);
                //   if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par][2]==3)&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
            if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par][2]=3;}

            par = abs((*newit)-pow(2,i));

            bool r = (*newit-pow(2,i)>0);
            cost3.insert(abs((*newit)-pow(2,i)));
            //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<-pow(2,i)<<endl;

            if(r){
                if((detail[par][2]==3)&(par==n))cout<<*newit<<" "<<-pow(2,i)<<endl;
                if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=-pow(2,i);detail[par][2]=3;}}
            else{
                if((detail[par][2]==3)&(par==n))cout<<-*newit<<" "<<pow(2,i)<<endl;
                if(detail[par][1]==0){
            //if(!get<1>(all.insert(par))&(par==n))cout<<(-*newit)<<" "<<pow(2,i)<<endl;
            detail[par][0]=-*newit;detail[par][1]=pow(2,i);detail[par][2]=3; }}


            }
        }
    }
     for(set<int>::iterator newit = cost2.begin(); newit!=cost2.end();newit++){
        for(int i =1; i<19;i++){
              //  all = cost2;
            par = pow(2,i)*(*newit);
            if(par<maxn-1){
                cost3.insert(par+1);
                    //if(!get<1>(all.insert(par))&(par+1==n))cout<<pow(2,i)*(*newit)<<" "<<1<<endl;
                if((detail[par+1][2]==3)&(par+1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if(detail[par+1][1]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par+1][0]=pow(2,i)*(*newit);detail[par+1][1]=1; detail[par+1][2]=3;   }
                cost3.insert(par-1);
                if((detail[par-1][2]==3)&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                //if(!get<1>(all.insert(par))&(par-1==n))cout<<pow(2,i)*(*newit)<<" "<<-1<<endl;
                if(detail[par-1][1]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par-1][0]=pow(2,i)*(*newit);detail[par-1][1]=-1;detail[par-1][2]=3;   }


            }

        }

     }
   //end of cost3

   //cost 4 part

   // multi subpart


    for(set<int>::iterator newit = cost3.begin(); newit!=cost3.end();newit++){
  // all = cost3;
        for(set<int>::iterator it2 = cost1.begin(); it2!=cost1.end();it2++){


            par = (*newit)*(*it2);

            if(par<maxn){
                      cost4.insert(par);
                  //  if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=4;}

            }
        }
    }

    for(set<int>::iterator newit = cost2.begin(); newit!=cost2.end();newit++){
           // all = cost3;
        for(set<int>::iterator it2 = cost2.begin(); it2!=cost2.end();it2++){

            par =(*newit)*(*it2);
            if(par<maxn){
                     cost4.insert(par);
                    // if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=4;}

            }
        }
   }

   // end of multi subpart
   //add subpart
     for(set<int>::iterator newit = cost3.begin(); newit!=cost3.end();newit++){
             //all = cost3;
            for(int i =1; i<19;i++){

                par = (*newit)+pow(2,i);
                if((par<maxn)&(abs((*newit)-pow(2,i))<maxn)){
                    cost4.insert(par);
                        //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par][2]=4;}


                par = abs((*newit)-pow(2,i));
                cost4.insert(abs((*newit)-pow(2,i)));

                bool r = ((*newit)-pow(2,i)>0);
                //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<(-pow(2,i))<<endl;

                if(r){
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<-pow(2,i)<<endl;
                    if(detail[par][1]==0){detail[par][0]=*newit;detail[par][2]=4;detail[par][1]=(-pow(2,i));}}
                else{
                    if((detail[par][2]==4)&(par==n))cout<<-*newit<<" "<<pow(2,i)<<endl;
                    if(detail[par][1]==0){if(!get<1>(all.insert(par))&(par==n))cout<<(-*newit)<<" "<<pow(2,i)<<endl;detail[par][2]=4;detail[par][0]=-*newit;detail[par][1]=pow(2,i);}}

                }

        }
    }

     for(set<int>::iterator newit = cost3.begin(); newit!=cost3.end();newit++){
          //  all = cost3;
        for(int i =1; i<19;i++){

                par = pow(2,i)*(*newit);

                if(par<maxn-1){
                    cost4.insert(par+1);
                         // if(!get<1>(all.insert(par+1))&(par+1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par+1][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par+1][0]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par+1][0]=pow(2,i)*(*newit);detail[par+1][1]=1;detail[par+1][2]=4;}
                cost4.insert(par-1);
              //  if(!get<1>(all.insert(par+1))&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par-1][2]==4)&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par-1][0]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par-1][0]=pow(2,i)*(*newit);detail[par-1][1]=-1;detail[par-1][2]=4;}


            }

        }

     }
     //leapfrog part

   //end of cost4


   // cost5 cases
   //additive


   // multi subpart


    for(set<int>::iterator newit = cost4.begin(); newit!=cost4.end();newit++){
  // all = cost3;
        for(set<int>::iterator it2 = cost1.begin(); it2!=cost1.end();it2++){


            par = (*newit)*(*it2);

            if(par<maxn){
                      cost5.insert(par);
                  //  if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=4;}

            }
        }
    }

    for(set<int>::iterator newit = cost3.begin(); newit!=cost3.end();newit++){
           // all = cost3;
        for(set<int>::iterator it2 = cost2.begin(); it2!=cost2.end();it2++){

            par =(*newit)*(*it2);
            if(par<maxn){
                     cost5.insert(par);
                    // if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=4;}

            }
        }
   }

   // end of multi subpart
   //add subpart
     for(set<int>::iterator newit = cost4.begin(); newit!=cost4.end();newit++){
             //all = cost3;
            for(int i =1; i<19;i++){

                par = (*newit)+pow(2,i);
                if((par<maxn)&(abs((*newit)-pow(2,i))<maxn)){
                    cost5.insert(par);
                        //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par][2]=4;}


                par = abs((*newit)-pow(2,i));
                cost5.insert(abs((*newit)-pow(2,i)));

                bool r = ((*newit)-pow(2,i)>0);
                //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<(-pow(2,i))<<endl;

                if(r){
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<-pow(2,i)<<endl;
                    if(detail[par][1]==0){detail[par][0]=*newit;detail[par][2]=4;detail[par][1]=(-pow(2,i));}}
                else{
                    if((detail[par][2]==4)&(par==n))cout<<-*newit<<" "<<pow(2,i)<<endl;
                    if(detail[par][1]==0){if(!get<1>(all.insert(par))&(par==n))cout<<(-*newit)<<" "<<pow(2,i)<<endl;detail[par][2]=4;detail[par][0]=-*newit;detail[par][1]=pow(2,i);}}

                }

        }
    }

     for(set<int>::iterator newit = cost4.begin(); newit!=cost4.end();newit++){
          //  all = cost3;
        for(int i =1; i<19;i++){

                par = pow(2,i)*(*newit);

                if(par<maxn-1){
                    cost5.insert(par+1);
                         // if(!get<1>(all.insert(par+1))&(par+1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par+1][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par+1][0]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par+1][0]=pow(2,i)*(*newit);detail[par+1][1]=1;detail[par+1][2]=4;}
                cost5.insert(par-1);
              //  if(!get<1>(all.insert(par+1))&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par-1][2]==4)&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par-1][0]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par-1][0]=pow(2,i)*(*newit);detail[par-1][1]=-1;detail[par-1][2]=4;}


            }

        }

     }

     // special case for cost5
      for(set<int>::iterator newit = cost2.begin(); newit!=cost2.end();newit++){
         for(set<int>::iterator it2 = cost2.begin(); it2!=cost2.end();it2++){
          //  all = cost3;
        for(int i =1; i<19;i++){

                par = pow(2,i)*(*newit);

                if(par<maxn-1){
                    cost5.insert(par+1);
                         // if(!get<1>(all.insert(par+1))&(par+1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par+1][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par+1][0]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par+1][0]=pow(2,i)*(*newit);detail[par+1][1]=1;detail[par+1][2]=4;}
                cost5.insert(par-1);
              //  if(!get<1>(all.insert(par+1))&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par-1][2]==4)&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par-1][0]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par-1][0]=pow(2,i)*(*newit);detail[par-1][1]=-1;detail[par-1][2]=4;}


            }

        }

     }
   //end of additive

   //muli part
   //end of multi part

   // leapfrog part

   //end of leapfrog



   // cost6 cases
   //additive
   //cost 4 part

   // multi subpart


    for(set<int>::iterator newit = cost5.begin(); newit!=cost5.end();newit++){
  // all = cost3;
        for(set<int>::iterator it2 = cost1.begin(); it2!=cost1.end();it2++){


            par = (*newit)*(*it2);

            if(par<maxn){
                      cost6.insert(par);
                  //  if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=4;}

            }
        }
    }

    for(set<int>::iterator newit = cost4.begin(); newit!=cost4.end();newit++){
           // all = cost3;
        for(set<int>::iterator it2 = cost2.begin(); it2!=cost2.end();it2++){

            par =(*newit)*(*it2);
            if(par<maxn){
                     cost6.insert(par);
                    // if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=4;}

            }
        }
   }
    for(set<int>::iterator newit = cost3.begin(); newit!=cost3.end();newit++){
           // all = cost3;
        for(set<int>::iterator it2 = cost3.begin(); it2!=cost3.end();it2++){

            par =(*newit)*(*it2);
            if(par<maxn){
                     cost6.insert(par);
                    // if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<*it2<<endl;
                    if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=*it2;detail[par][2]=4;}

            }
        }
   }

   // end of multi subpart
   //add subpart
     for(set<int>::iterator newit = cost5.begin(); newit!=cost5.end();newit++){
             //all = cost3;
            for(int i =1; i<19;i++){

                par = (*newit)+pow(2,i);
                if((par<maxn)&(abs((*newit)-pow(2,i))<maxn)){
                    cost6.insert(par);
                        //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if(detail[par][1]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par][2]=4;}


                par = abs((*newit)-pow(2,i));
                cost6.insert(abs((*newit)-pow(2,i)));

                bool r = ((*newit)-pow(2,i)>0);
                //if(!get<1>(all.insert(par))&(par==n))cout<<*newit<<" "<<(-pow(2,i))<<endl;

                if(r){
                    if((detail[par][2]==4)&(par==n))cout<<*newit<<" "<<-pow(2,i)<<endl;
                    if(detail[par][1]==0){detail[par][0]=*newit;detail[par][2]=4;detail[par][1]=(-pow(2,i));}}
                else{
                    if((detail[par][2]==4)&(par==n))cout<<-*newit<<" "<<pow(2,i)<<endl;
                    if(detail[par][1]==0){if(!get<1>(all.insert(par))&(par==n))cout<<(-*newit)<<" "<<pow(2,i)<<endl;detail[par][2]=4;detail[par][0]=-*newit;detail[par][1]=pow(2,i);}}

                }

        }
    }

     for(set<int>::iterator newit = cost5.begin(); newit!=cost5.end();newit++){
          //  all = cost3;
        for(int i =1; i<19;i++){

                par = pow(2,i)*(*newit);

                if(par<maxn-1){
                    cost6.insert(par+1);
                         // if(!get<1>(all.insert(par+1))&(par+1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par+1][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par+1][0]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par+1][0]=pow(2,i)*(*newit);detail[par+1][1]=1;detail[par+1][2]=4;}
                cost6.insert(par-1);
              //  if(!get<1>(all.insert(par+1))&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par-1][2]==4)&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par-1][0]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par-1][0]=pow(2,i)*(*newit);detail[par-1][1]=-1;detail[par-1][2]=4;}


            }

        }

     }
     //special case for cost 6
      for(set<int>::iterator newit = cost3.begin(); newit!=cost2.end();newit++){
           for(set<int>::iterator newit = cost3.begin(); newit!=cost2.end();newit++){
          //  all = cost3;
        for(int i =1; i<19;i++){

                par = pow(2,i)*(*newit);

                if(par<maxn-1){
                    cost6.insert(par+1);
                         // if(!get<1>(all.insert(par+1))&(par+1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                    if((detail[par+1][2]==4)&(par==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par+1][0]==0){ detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par+1][0]=pow(2,i)*(*newit);detail[par+1][1]=1;detail[par+1][2]=4;}
                cost6.insert(par-1);
              //  if(!get<1>(all.insert(par+1))&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<endl;
                if((detail[par-1][2]==4)&(par-1==n))cout<<*newit<<" "<<pow(2,i)<<1<<endl;
                if(detail[par-1][0]==0){detail[par][0]=*newit;detail[par][1]=pow(2,i);detail[par-1][0]=pow(2,i)*(*newit);detail[par-1][1]=-1;detail[par-1][2]=4;}


            }

        }

     }
 }
   //end of additive

   //muli part
   //end of multi part

   // leapfrog part

   //end of leapfrog
   //end of cost 6
   if(n%2==1){
   if(cost1.find(n)!=cost1.end()){showfac(detail,n);cout<<endl;cout<<"cost 1\n"; }
   else if(cost2.find(n)!=cost2.end()){showfac(detail,n);cout<<endl;cout<<"cost 2\n"; }
   else if(cost3.find(n)!=cost3.end()){showfac(detail,n);cout<<endl;cout<<"cost 3\n";}
   else if(cost4.find(n)!=cost4.end()){showfac(detail,n);cout<<endl;cout<<"cost 4\n";}
   }


}
int main(){
    int c =100;

    int number;
    do {
    cout<<"\n********************************\n";
    cout<<"input your number:  ";
    cin>>number;
    check(number);
    }while ((c--)>0);


    return 0;
}
