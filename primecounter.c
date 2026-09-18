/**
 * Length-Codegolfed adaptation of user Dennis' C code to compute prime-counting function pi(n) while maintaining theoretical speed and not sacrificing (device-dependent) practical runtime too much, if any.
 * See https://codegolf.stackexchange.com/questions/74269/calculate-the-number-of-primes-up-to-n
 * Code begins after this line. To use it, you need GCC or Clang (uses unsigned __int128 and __builtin_* intrinsics), then call ./a.out n with 0 <= n < 2^31, which prints pi(n) to stdout.
 */
#include<math.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define R (47*a+3>>1)
#define S v[i>>7]>>i/2%64&1
#define G(x) (x<30030?g[x+1>>1]:x/30030*5760+g[x%30030+1>>1])
#define K(i,p,o,m) j|=m<<i,i+=i+o<p?o:o-p
uint64_t a,q[4792]={2,3,5,7,11,13,17,19};uint16_t g[15016],*h;uint64_t F(uint64_t x,uint64_t c){uint64_t*d=q+8,i=0,r=G(x)-G(x/17),t=x/19;while(i<c&&t>47*a)r-=F(t,i++),t=(unsigned __int128)x**d++>>64;while(i<c&&t)r-=h[i++*R+(t+1>>1)],t=(unsigned __int128)x**d++>>64;return r;}int main(int z,char**o){uint64_t i,j,k,n,s,*p,t=8,x=atoi(o[1]),r=sqrt(x),c=cbrt(x)+1e-9,e,*v;uint16_t d[]={0,1,1,1,2,2,3,4,4,5,6,6,7,7,7,8},*l,*m,u[106]={1,2,3,5,6,8,9},y[1156];if(x<529){for(e=i=0;i<8;i++)e+=q[i]<=x;for(i=21;i<=x;i+=2)e+=i%3&&i%5&&i%7&&i%11&&i%13&&i%17&&i%19;return!printf("%lu\n",e);}e=x/c+2>>1;k=e+63>>6;v=malloc(k*8);for(i=0;i<k;i++)j=0,K(u[0],3,2,0x9249249249249249),K(u[1],5,1,0x1084210842108421U),K(u[2],7,6,0x8102040810204081),K(u[3],11,2,0x80100200400801U),K(u[4],13,1,0x10008004002001U),K(u[5],17,4,0x8000400020001U),K(u[6],19,12,0x200004000080001U),v[i]=~j;n=e>>17?131072:e;for(i=21;i<=c;i+=2)if(S)for(q[t++]=i,j=i*i/2;j<n;j+=i)v[j>>6]&=~(1ULL<<j%64);a=t;for(i=c+1|1;i<=r;i+=2)if(S)q[t++]=i;while(n<e)for(i=2*n+1,n+=131072,n=n<e?n:e,p=q+8;p<q+a;p++)for(j=((i/ *p|1)<=*p?*p:i/ *p|1)**p/2;j<n;j+=*p)v[j>>6]&=~(1ULL<<j%64);s=(t-a)*(a+t-1)/2;for(i=r+1>>1,e=t;e-->a;s-=t)for(n=x/q[e]+1>>1;i<n;i=k)k=i|63,k=k<n?k+1:n,t+=__builtin_popcountll(v[i>>6]>>i%64&~0ULL>>64-k+i);a-=7,h=malloc(a*R*2);for(i=0;i<15016;i++)i<106?u[i]=i/15*8+d[i%15]-d[(i+3)/7]:0,i<1156?y[i]=i/105*48+u[i%105]-u[(i+5)/11]:0,g[i]=i/1155*480+y[i%1155]-y[(i+6)/13],i<R?h[i]=g[i]-g[(i+8)/17]:0;for(m=h+R,p=q+7;m<h+a*R;m+=R,p++)for(memcpy(m,m-R,R*2),l=m+*p/2+1,i=1;l<m+R;)for(k=m+R-l<*p?m+R-l:*p,t=*(m-R+i++);k--;)*l++-=t;for(p=q+8;p<q+a+8;p++)t=96-__builtin_clzll(*p),*p=(1ULL<<t)/ *p+1<<64-t;printf("%lu\n",F(x,a)+a+6+s);}
