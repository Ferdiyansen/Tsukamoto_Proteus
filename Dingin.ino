void Dingin()
{
  if (aktual <= 25)
  {
    dingin = 1;
  }
  else if (aktual > 25 && aktual < 75)
  {
    dingin = (75-aktual) / (75 - 25);
  }
  else if (aktual >= 75)
  {
    dingin = 0;
  }
}
