#!/bin/sh -ax

#Send out the serial command in Hex code

 echo -e "\x9B\x11\x00\x32\xCD\x0D" > /dev/ttyS0					


#Redirect the browser back to the index page

 echo "Content-type: text/html"
 echo ""
 echo "<html><head><title>Demo</title>"
 echo "</head><body>"
 echo "<script type="text/javascript"><!--"
 echo "setTimeout('Redirect()',0);"
 echo " function Redirect(){  location.href = '../index.html';}"
 echo " --></script></body></html>"