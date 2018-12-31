from bs4 import BeautifulSoup as bs
import urllib2

webpage = urllib2.urlopen("https://stanford.edu/~stepp/cppdoc/doxygen/gwindow_8h_source.html")
url = webpage.read()
webpage.close()

soup = bs(url)
