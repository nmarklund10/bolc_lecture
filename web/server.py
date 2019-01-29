import SimpleHTTPServer
import SocketServer
import commands

PORT = 8000

Handler = SimpleHTTPServer.SimpleHTTPRequestHandler

httpd = SocketServer.TCPServer(("", PORT), Handler)

print("Type the following commands in order to download files:")

ip = "10.50.21.2"
print("    wget %s:%d/bomb" % (ip, PORT))
print("    wget %s:%d/slides.pdf" % (ip, PORT))
print("    chmod +x bomb")
httpd.serve_forever()
