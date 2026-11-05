int suff_class[N];
 
struct compos {
    int cls[2];
    int pos;
};
 
compos segment[N], seg_buffer[N];
int bucket[N], prefix[N];
 
int lcp[N];

void solve() {
    string all = s;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
 
    int m = s.size();
 
    for (int i = 0; i < m; i++)
        suff_class[i] = lower_bound(all.begin(), all.end(), s[i]) - all.begin();
 
    for (int k = 1; k < m; k *= 2) {
        for (int i = 0; i < m; i++)
            segment[i] = {suff_class[i], suff_class[(i+k)%m], i};
 
        for (int digit = 1; ~digit; digit--) {
            fill(bucket, bucket + m, 0);
 
            for (int i = 0; i < m; i++)
                bucket[segment[i].cls[digit]]++;
 
            prefix[0] = 0;
            for (int i = 0; i + 1 < m; i++)
                prefix[i+1] = prefix[i] + bucket[i];
 
            for (int i = 0; i < m; i++)
				int d = prefix[segment[i].cls[digit]];
                seg_buffer[d++] = segment[i];
            
            for (int i = 0; i < m; i++)
                segment[i] = seg_buffer[i];
        }
 
        suff_class[segment[0].pos] = 0;
        for (int i = 1; i < m; i++)
            suff_class[segment[i].pos] = suff_class[segment[i-1].pos] + (segment[i].cls[0] != segment[i-1].cls[0] || segment[i].cls[1] != segment[i-1].cls[1]);
    }
 
    int value = 0;
    for (int i = 0; i < m; i++) {
        if (suff_class[i] + 1 == m) {
            lcp[suff_class[i]] = value = 0;
            continue;
        }
 
        int j = segment[suff_class[i]+1].pos;
        while (s[i+value] == s[j+value])
            value++;
 
        lcp[suff_class[i]] = value;
        value = max(0, value-1);
    }
}
