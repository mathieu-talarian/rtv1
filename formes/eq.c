#include        <math.h>

#define        ABS(x)        (((x) <= -0.000000001) ? -(x) : (x))

double                resolve2(double a, double b, double c, double *ret)
{
  double        delta;

  delta = (b * b) - (4.0 * a * c);
  if (delta >= -0.000000001 && delta <= 0.000000001)
    {
      ret[0] = -b / (2.0 * a);
      return (ret[0]);
    }
  else if (delta > 0)
    {
      ret[0] = (-b - sqrt(delta)) / (2.0 * a);
      ret[1] = (-b + sqrt(delta)) / (2.0 * a);
      return ((ret[1] > ret[0]) ? ret[1] : ret[0]);
    }
  ret[0] = -1;
  ret[1] = -1;
  return (-1);
}

double                resolve3_r3(double r, double q, double a2)
{
  double        Dp;
  double        t;
  double        s;
  int      i;
  double        ret[3];

  Dp = r / pow(q, 1.5);
  t = acos(Dp) / 3.0;
  s = -2.0 * sqrt(q);
  for (i = 0; i <= 2; i++)
    ret[i] = s * cos(t + 2.0 * M_PI * i / 3.0) - a2 / 3.0;
  if (ret[0] >= ret[1] && ret[0] >= ret[2])
    return (ret[0]);
  else if (ret[1] >= ret[2])
    return (ret[1]);
  else
    return (ret[0]);
}

double                resolve3_r1(double D, double r, double q, double a2)
{
  double        s;

  s = pow(sqrt(-D) + ABS(r), 1.0 / 3.0);
  if (r < 0)
    return (s + q / s - a2 / 3.0);
  else
    return (-s - (q / s) - (a2 / 3.0));
}

double                resolve3(double a3, double a2, double a1, double a0)
{
  double        q;
  double        r;
  double        D;

  a2 = a2 / a3;
  a1 = a1 / a3;
  a0 = a0 / a3;
  q = (a2 * a2 - 3.0 * a1) / 9.0;
  r = (a2 * (a2 * a2 - 4.5 * a1) + 13.5 * a0) / 27.0;
  D = q * q * q - r * r;
  if (D > 0)
    return (resolve3_r3(r, q, a2));
  else
    return (resolve3_r1(D, r, q, a2));
}

double                select4(double *ret)
{
  double        r;
  int      i;

  r = -1;
  for (i = 0; i < 4; i++)
    {
      if ((ret[i] < r || r == -1) && ret[i] > 0)
        r = ret[i];
    }
  return (r);
}

double        resolve4(double div, double a, double b, double c, double d)
{
  double        p[3];
  double        R[3];
  double        ret[4];
  int      i;

  a = a / div;
  b = b / div;
  c = c / div;
  d = d / div;
  p[0] = -(3.0 / 8.0) * a * a + b;
  p[1] = (1.0 / 8.0) * a * a * a - (1.0 / 2.0) * a * b + c;
  p[2] = -(3.0 / 256.0) * a * a * a * a + (1.0 / 16.0) * a * a * b
    - (1.0 / 4.0) * a * c + d;
  R[0] = resolve3(1, -(p[0] / 2.0), - p[2], ((1.0 / 2.0) * p[0] * p[2])
                  - ((1.0 / 8.0) * p[1] * p[1]));
  R[2] = sqrt(R[0] * R[0] - p[2]);
  R[1] = p[1] / (-2 * R[2]);
  resolve2(1, R[1], R[0] + R[2], ret);
  resolve2(1, -R[1], R[0] - R[2], ret + 2);
  for (i = 0; i < 4; i++)
    if (ret[i] != -1)
      ret[i] = ret[i] - a / 4.0;
  return (select4(ret));
}
