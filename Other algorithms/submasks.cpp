int submask = mask;
while (submask > 0) {
	submask--;
	submask &= mask;
}
