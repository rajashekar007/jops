main(a,b,c,t,r,p){scanf("%d",&t);while(t--){char d;scanf("%d%c%c%d%c%c%d",&a,&d,&d,&b,&d,&d,&c);if(a<b){p=a;a=b;b=p;}r=a%b;while(r){a=b;b=r;r=a%b;}c%b?printf("no\n"):printf("yes\n");}return 0;}