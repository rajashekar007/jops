g(i){return i<2?2:g(i-1)*(4*i-2)/i;}k="%d\n";main(t,n){for(scanf(k,&t);t--;scanf(k,&n),printf(k,g(n)));return 0;}