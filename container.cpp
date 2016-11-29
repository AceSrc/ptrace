#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include "webkit.h"
int main(int argc, char *argv[]) {
	if (argc != 2) return 0;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	pid_t pid = fork();
	if (pid == 0) {
		execv(argv[1], NULL);
	}
	else {
		printf("%d\n", &xmlin);
		printf("%d\n", &xmlout);
		printf("%d\n", dpoints);
		printf("%d\n", dlines);
		wait(NULL);
	}
	return 0;
}
