void Besar()
{
  if (set_temperature <= 25)
  {
    besar = 0;
  }
  else if (set_temperature > 25 && set_temperature < 75)
  {
    besar = (set_temperature - 25) / (75 - 25);
  }
  else if (set_temperature >= 75)
  {
    besar = 1;
  }
}
