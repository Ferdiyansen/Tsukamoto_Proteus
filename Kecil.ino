void Kecil()
{
  if (set_temperature <= 25)
  {
    kecil = 1;
  }
  else if (set_temperature > 25 && set_temperature < 75)
  {
    kecil = (75-set_temperature) / (75 - 25);
  }
  else if (set_temperature >= 75)
  {
    kecil = 0;
  }
}
