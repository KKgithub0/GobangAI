#pragma once
class panding34
{
public:
	panding34();
	~panding34();


public:

	//以下参数用以回传之后放置白子的坐标
	int blackV = 0;
	int whiteV = 0;
	int bz = 0;
	int wz = 0;
	int bxf = 0;
	int wxf = 0;
	int bxz = 0;
	int wxz = 0;


	//判定连三、连四的方法。f表示连F
	int panding(int f, int t[][19]) {
		int fl = 0;

		if (f == 4)
		{
			int flag1 = 1;
			for (int i = 0;i < 19;i++)
			{
				for (int j = 0;j < 19;j++)
				{
					if (t[i][j] == 1 && whiteV < f)
					{
						blackV++;whiteV = 0;
					}
					else
					{
						if (t[i][j] == 2 && blackV < f)
						{
							whiteV++;blackV = 0;
						}
						else
						{
							whiteV = 0;blackV = 0;
						}
					}
					if (blackV == f && (t[i][j + 1] != 2 || t[i][j - f] != 2)) { fl = 1; flag1 = 0;blackV = i;whiteV = j;break; }
					if (whiteV == f && (t[i][j + 1] != 1 || t[i][j - f] != 1)) { fl = 2; flag1 = 0;blackV = i;whiteV = j;break; }
				}
				if (flag1 == 0) break;
			}



			int flag2 = 1;
			for (int i = 0;i < 19;i++)
			{
				for (int j = 0;j < 19;j++)
				{
					if (t[j][i] == 1 && wz < f)
					{
						bz++;wz = 0;
					}
					else
					{
						if (t[j][i] == 2 && bz < f)
						{
							wz++;bz = 0;
						}
						else { wz = 0;bz = 0; }
					}
					if (bz == f && (t[j + 1][i] != 2 || t[j - f][i] != 2)) { fl = 1;flag2 = 0;bz = j;wz = i;break; }
					if (wz == f && (t[j + 1][i] != 1 || t[j - f][i] != 1)) { fl = 2;flag2 = 0;bz = j;wz = i;break; }
				}
				if (flag2 == 0)break;
			}


			int flag3 = 1;
			for (int i = 0;i < 19;i++) {
				for (int j = 0;j < 19;j++)
				{
					if (t[i][j] == 1 && wxf < f)
					{
						for (int m = i, n = j;m < 19 && n < 19;m++, n++)
						{
							if (t[m][n] == 1)
							{
								bxf++;wxf = 0;
							}
							else
							{
								if (bxf < f) bxf = 0;wxf = 0;
							}
						}
					}
					else
					{
						if (t[i][j] == 2 && bxf < f)
						{
							for (int m = i, n = j;m < 19 && n < 19;m++, n++)
							{
								if (t[m][n] == 2)
								{
									wxf++;bxf = 0;
								}
								else
								{
									if (wxf < f) wxf = 0;bxf = 0;
								}
							}
						}
						else { bxf = 0;wxf = 0; }
					}
					if (bxf == f && (t[i - 1][j - 1] != 2 || t[i + f][j + f] != 2)) { fl = 1;flag3 = 0;bxf = i;wxf = j;break; }
					if (wxf == f && (t[i - 1][j - 1] != 1 || t[i + f][j + f] != 1)) { fl = 2;flag3 = 0;bxf = i;wxf = j;break; }
				}
				if (flag3 == 0) break;
			}



			int flag4 = 1;
			for (int i = 0;i < 19;i++) {
				for (int j = 0;j < 19;j++)
				{
					if (t[i][j] == 1 && wxz < f)
					{
						for (int m = i, n = j;m < 19 && m >= 0 && n < 19 && n >= 0;m++, n--)
						{
							if (t[m][n] == 1)
							{
								bxz++;wxz = 0;
							}
							else {
								if (bxz < f) bxz = 0;wxz = 0;
							}
						}
					}
					else
					{
						if (t[i][j] == 2 && bxz < f)
						{
							for (int m = i, n = j;m < 19 && m >= 0 && n < 19 && n >= 0;m++, n--)
							{
								if (t[m][n] == 2)
								{
									wxz++;bxz = 0;
								}
								else {
									if (wxz < f) wxz = 0;bxz = 0;
								}
							}
						}
						else { bxz = 0;wxz = 0; }
					}
					if (bxz == f && (t[i - 1][j + 1] != 2 || t[i + f][j - f] != 2)) { fl = 1;flag4 = 0;bxz = i;wxz = j;break; }
					if (wxz == f && (t[i - 1][j + 1] != 1 || t[i + f][j - f] != 1)) { fl = 2;flag4 = 0;bxz = i;wxz = j;break; }
				}
				if (flag4 == 0)break;
			}


			return fl;

		}


		if (f == 3) {

			int flag1 = 1;
			for (int i = 0;i < 19;i++)
			{
				for (int j = 0;j < 19;j++)
				{
					if (t[i][j] == 1 && whiteV < f)
					{
						blackV++;whiteV = 0;
					}
					else
					{
						if (t[i][j] == 2 && blackV < f)
						{
							whiteV++;blackV = 0;
						}
						else
						{
							whiteV = 0;blackV = 0;
						}
					}
					if (blackV == f&& t[i][j - f] == 0 && t[i][j + 1] == 0) { fl = 1; flag1 = 0;blackV = i;whiteV = j;break; }
					if (whiteV == f&& t[i][j - f] == 0 && t[i][j + 1] == 0) { fl = 2; flag1 = 0;blackV = i;whiteV = j;break; }
				}
				if (flag1 == 0) break;
			}



			int flag2 = 1;
			for (int i = 0;i < 19;i++)
			{
				for (int j = 0;j < 19;j++)
				{
					if (t[j][i] == 1 && wz < f)
					{
						bz++;wz = 0;
					}
					else
					{
						if (t[j][i] == 2 && bz < f)
						{
							wz++;bz = 0;
						}
						else { wz = 0;bz = 0; }
					}
					if (bz == f && (t[j - f][i] == 0 && t[j + 1][i] == 0)) { fl = 1;flag2 = 0;bz = j;wz = i;break; }
					if (wz == f && (t[j - f][i] == 0 && t[j + 1][i] == 0)) { fl = 2;flag2 = 0;bz = j;wz = i;break; }
				}
				if (flag2 == 0)break;
			}


			int flag3 = 1;
			for (int i = 0;i < 19;i++) {
				for (int j = 0;j < 19;j++)
				{
					if (t[i][j] == 1 && wxf < f)
					{
						for (int m = i, n = j;m < 19 && n < 19;m++, n++)
						{
							if (t[m][n] == 1)
							{
								bxf++;wxf = 0;
							}
							else
							{
								if (bxf < f) bxf = 0;wxf = 0;
							}
						}
					}
					else
					{
						if (t[i][j] == 2 && bxf < f)
						{
							for (int m = i, n = j;m < 19 && n < 19;m++, n++)
							{
								if (t[m][n] == 2)
								{
									wxf++;bxf = 0;
								}
								else
								{
									if (wxf < f) wxf = 0;bxf = 0;
								}
							}
						}
						else { bxf = 0;wxf = 0; }
					}
					if (bxf == f && (t[i - 1][j - 1] == 0 && t[i + f][j + f] == 0)) { fl = 1;flag3 = 0;bxf = i;wxf = j;break; }
					if (wxf == f && (t[i - 1][j - 1] == 0 && t[i + f][j + f] == 0)) { fl = 2;flag3 = 0;bxf = i;wxf = j;break; }
				}
				if (flag3 == 0) break;
			}



			int flag4 = 1;
			for (int i = 0;i < 19;i++) {
				for (int j = 0;j < 19;j++)
				{
					if (t[i][j] == 1 && wxz < f)
					{
						for (int m = i, n = j;m < 19 && m >= 0 && n < 19 && n >= 0;m++, n--)
						{
							if (t[m][n] == 1)
							{
								bxz++;wxz = 0;
							}
							else {
								if (bxz < f) bxz = 0;wxz = 0;
							}
						}
					}
					else
					{
						if (t[i][j] == 2 && bxz < f)
						{
							for (int m = i, n = j;m < 19 && m >= 0 && n < 19 && n >= 0;m++, n--)
							{
								if (t[m][n] == 2)
								{
									wxz++;bxz = 0;
								}
								else {
									if (wxz < f) wxz = 0;bxz = 0;
								}
							}
						}
						else { bxz = 0;wxz = 0; }
					}
					if (bxz == f && (t[i - 1][j + 1] == 0 && t[i + f][j - f] == 0)) { fl = 1;flag4 = 0;bxz = i;wxz = j;break; }
					if (wxz == f && (t[i - 1][j + 1] == 0 && t[i + f][j - f] == 0)) { fl = 2;flag4 = 0;bxz = i;wxz = j;break; }
				}
				if (flag4 == 0)break;
			}


			return fl;


		}


		return fl;
	}

};




