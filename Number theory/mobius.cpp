int divider[N+1]
int mu[N+1], phi[N+1];
for (int i = 1; i <= N; i++)
    phi[i] = i;
for (int i = 2; i <= N; i++) {
	if (divider[i] == 0) {
    	divider[i] = i;
    	for (int j = i; j <= N; j += i) {
    		phi[j] -= phi[j] / i;
        	if (divider[j] == 0)
        		divider[j] = i;
    	}
   	}
    if (divider[i] == divider[i / divider[i]])
		mu[i] = 0;
    else mu[i] = -mu[i / divider[i]];
}
