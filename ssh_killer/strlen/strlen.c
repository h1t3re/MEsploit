unsigned int strlen(const char *str)
{
	unsigned int len = 0;
	while(*(str+len) != '\0')
		len = len +1;
	return len +1;
}
