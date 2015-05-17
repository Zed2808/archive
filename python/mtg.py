import urllib2
import random

def getname():
	while(True):
		page = urllib2.urlopen('http://gatherer.wizards.com/Pages/Card/Details.aspx?multiverseid=' + str(random.randint(1, 383159)))
		source = page.read()
		namestart = source.find('<title>')
		nameend = source.find('(', namestart)
		name = source[namestart + 10:nameend]

		if name[:31] != 'Gatherer - Magic: The Gathering':
			return name

print getname()

