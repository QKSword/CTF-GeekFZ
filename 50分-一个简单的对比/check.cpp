#include <stdio.h>
#include <Windows.h>
int check_flag(char flag[]);

int main()
{
	char flag[MAX_PATH];
	printf("输入的flag为：");
	gets_s(flag);
	check_flag(flag);
	return 0;
}

int check_flag(char flag[])
{
	if(flag[0] == 'f')
	{
		if(flag[1] == 'l')
		{
			if(flag[2] == 'a')
			{
				if(flag[3] == 'g')
				{
					if(flag[4] == '{')
					{
						if(flag[5] == 's')
						{
							if(flag[6] == 'A')
							{
								if(flag[7] == 'd')
								{
									if(flag[8] == 'f')
									{
										if(flag[9] == '_')
										{
											if(flag[10] == 'f')
											{
												if(flag[11] == 'D')
												{
													if(flag[12] == 'f')
													{
														if(flag[13] == 'k')
														{
															if(flag[14] == 'l')
															{
																if(flag[15] == '_')
																{
																	if(flag[16] == 'F')
																	{
																		if(flag[17] == 'd')
																		{
																			if(flag[18] == 'f')
																			{
																				if(flag[19] == '}')
																				{
																					printf("yes,this is a flag");
																					getchar();
																					return 0;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else
	{
		return 0;
	}
}