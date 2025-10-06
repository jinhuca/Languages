t2 = { 'FtoK': lambda deg_f: 273.15 + (deg_f - 32) * 5 /9,
       'CtoK': lambda deg_c: 273.15 + deg_c }

print(t2['FtoK'](32))