from cythonregex import regex_find_ip_addresses
from time import perf_counter
with open(r"C:\Users\hansc\Downloads\log20250228\log20250228.csv", "r", encoding="utf-8") as f:
    data = f.read()
print("start")
start=perf_counter()
esult = regex_find_ip_addresses(data)
print(perf_counter()-start)
