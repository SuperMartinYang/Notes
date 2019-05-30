import pymysql
class TestConnection:

    def canConnect(self, server, port, user, passwd, schema):
        try:
            db = pymysql.connect(host=server, port=port, user=user, passwd=passwd, db=schema)
            cursor = db.cursor()        
            cursor.execute("SELECT VERSION()")
            results = cursor.fetchone()
            # Check if anything at all is returned
            if results:
                return True
            else:
                return False               
        except pymysql.Error:
            print("ERROR IN CONNECTION")
        return False
    
pymysql.install_as_MySQLdb()
print(TestConnection().canConnect("192.168.99.100", 32769, "root", "helloworld", "Test"))