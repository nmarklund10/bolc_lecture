import SimpleHTTPServer
import SocketServer

PORT = 8000

Handler = SimpleHTTPServer.SimpleHTTPRequestHandler

httpd = SocketServer.TCPServer(("", PORT), Handler)

print("Type the following commands in order to download file:")
print("    wget 10.50.21.2:%d/bomb" % PORT)
print("    chmod +x bomb")
httpd.serve_forever()
