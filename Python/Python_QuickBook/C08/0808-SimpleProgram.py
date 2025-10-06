###################### 8.3 Word counting

import string
SampleString = "To be or not to be"
occurrences = {}
for word in SampleString.split():
	occurrences[word] = occurrences.get(word, 0) + 1
	
for word in occurrences.keys():
	print("The word", word, "occurs", occurrences[word], "time(s) in the string")
