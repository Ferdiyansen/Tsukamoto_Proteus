void Panas()
{
  if (aktual <= 25)
  {
    panas = 0;
  }
  else if (aktual > 25 && aktual < 75)
  {
    panas = (aktual - 25) / (75 - 25);
  }
  else if (aktual >= 75)
  {
    panas = 1;
  }
}
