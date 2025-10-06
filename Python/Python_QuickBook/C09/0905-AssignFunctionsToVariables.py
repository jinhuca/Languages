def f_to_kelvin(degrees_f):
  return 273.15 + (degrees_f - 32) * 5 / 9

def c_to_kelvin(degrees_c):
  return 273.15 + degrees_c

abs_temperature = f_to_kelvin
abs_temperature(32)