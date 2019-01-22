import SimpleHTTPServer
import SocketServer
import commands

PORT = 8000

Handler = SimpleHTTPServer.SimpleHTTPRequestHandler

httpd = SocketServer.TCPServer(("", PORT), Handler)

print("Type the following commands in order to download file:")

status, ip = commands.getstatusoutput("ip addr | grep 'inet ' | awk '{print $2}' | tr '/' ' ' | awk '{print $1}' | tail -n 1")
print("    wget %s:%d/bomb" % (ip, PORT))
print("    chmod +x bomb")
httpd.serve_forever()
