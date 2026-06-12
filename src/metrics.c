#include <stdio.h>
#include <stdlib.h>

__attribute__((visibility("default"))) void run() {
    FILE *fp = fopen("/proc/net/tcp", "r");
    if (!fp) return;
    
    FILE *out = fopen("/mnt/user-data/outputs/metrics_dump.json", "w");
    if (!out) {
        fclose(fp);
        return;
    }
    
    char buf[4096];
    fprintf(out, "{\n  \"tcp_connections\": [\n");
    int first = 1;
    while (fgets(buf, sizeof(buf), fp)) {
        if (!first) fprintf(out, ",\n");
        first = 0;
        // Strip newline from fgets to keep valid JSON formatting
        int len = 0;
        while(buf[len] != '\0') {
            if(buf[len] == '\n') buf[len] = '\0';
            len++;
        }
        fprintf(out, "    \"%s\"", buf);
    }
    fprintf(out, "\n  ]\n}\n");
    
    fclose(out);
    fclose(fp);
}