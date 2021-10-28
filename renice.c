#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int pid = 0, nice = 99;

	if (!argv[1] && !argv[2])
		return 1;

	sscanf(argv[2], "%i", &pid);
	if (!pid || !kill(pid, 0))
		return 127;

	sscanf(argv[1], "%i", &nice);
	if (nice < -20 || nice > 19)
		return 255;

	return setpriority(pid, PRIO_PROCESS, nice);
}
