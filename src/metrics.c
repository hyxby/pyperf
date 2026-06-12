#include <stdio.h> 
#include <stdlib.h> 
 
void collect() { 
    FILE *fp = fopen("/proc/net/tcp", "r"); 
    if (!fp) return; 
 
    FILE *out = fopen("/mnt/user-data/outputs/system_metrics.json", "w"); 
    if (!out) { 
        fclose(fp); 
        return; 
    } 
 
    char buf[4096]; 
    while (fgets(buf, sizeof(buf), fp)) { 
        fputs(buf, out); 
    } 
 
    fclose(out); 
    fclose(fp); 
} 
