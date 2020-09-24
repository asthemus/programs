from flask import Flask,request,jsonify,session
from flask_sqlalchemy import SQLAlchemy
from flask_marshmallow import Marshmallow
import os
import datetime

#init app
app = Flask(__name__)
basedir = os.path.abspath(os.path.dirname(__file__))

#init db
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(basedir,'db.sqlite')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)
ma = Marshmallow(app)

class Bus(db.Model):
    id = db.Column(db.Integer,primary_key=True)
    name = db.Column(db.String(20),unique=True)
    src = db.Column(db.String(20))
    dest = db.Column(db.String(20))
    s_time = db.Column(db.String(20))
    e_time = db.Column(db.String(20))
    price = db.Column(db.Float)
    no_seats = db.Column(db.Integer)
    rem_seats = db.Column(db.Integer)

    mon_active = db.Column(db.Boolean)
    tues_active = db.Column(db.Boolean)
    wed_active = db.Column(db.Boolean)
    thurs_active = db.Column(db.Boolean)
    fri_active = db.Column(db.Boolean)
    sat_active = db.Column(db.Boolean)
    sun_active = db.Column(db.Boolean)

    def __init__(self,name,src,dest,s_time,e_time,price,no_seats,rem_seats,
    mon_active,tues_active,wed_active,thurs_active,fri_active,sat_active,sun_active):
        self.name = name
        self.src =src
        self.dest = dest
        self.s_time = s_time
        self.e_time = e_time
        self.price = price
        self.no_seats = no_seats
        self.rem_seats = rem_seats
        self.mon_active = mon_active
        self.tues_active = tues_active
        self.wed_active = wed_active
        self.thurs_active = thurs_active
        self.fri_active = fri_active
        self.sat_active = sat_active
        self.sun_active = sun_active

class Users(db.Model):
    id = db.Column(db.Integer,primary_key=True)
    name = db.Column(db.String(20))
    username = db.Column(db.String(20),unique=True)
    password = db.Column(db.Integer)

    def __init__(self,u_id,b_id,no_seats):
        self.name = name
        self.username =username
        self.password = password

class Reservations(db.Model):
    id = db.Column(db.Integer,primary_key=True)
    u_id = db.Column(db.Integer)
    b_id = db.Column(db.Integer)
    no_seats = db.Column(db.Integer)

    def __init__(self,u_id,b_id,no_seats):
        self.u_id = u_id
        self.b_id =b_id
        self.no_seats = no_seats

class BusSchema(ma.Schema):
    class Meta:
        fields = ('id','name','src','dest','s_time','e_time','price','no_seats','rem_seats',
        'mon_active','tues_active','wed_active','thurs_active','fri_active','sat_active','sun_active')

class ReservationSchema(ma.Schema):
    class Meta:
        fields = ('id','u_id','b_id','no_seats')


#create bus schema
bus_schema = BusSchema()
buses_schema = BusSchema(many=True)
#create reservation Schema
reservation_schema = ReservationSchema()
reservations_schema = ReservationSchema(many=True)

@app.route('/',methods=['GET'])
def home():
    return jsonify({'msg':'hello world'})

#get all buses
@app.route('/getbuses',methods=['GET'])
def getbuses():
    all_buses = Bus.query.all()
    result = buses_schema.dump(all_buses)
    return jsonify(result)

#get single buses
@app.route('/getbus/<id>',methods=['GET'])
def getbus(id):
    bus = Bus.query.get(id)
    return bus_schema.jsonify(bus)

#add bus
@app.route('/addbus',methods=['POST'])
def add_bus():
    name = request.json['name']
    src =request.json['src']
    dest = request.json['dest']
    s_time = request.json['s_time']
    e_time = request.json['e_time']
    price = request.json['price']
    no_seats = request.json['no_seats']
    rem_seats = no_seats
    mon_active = request.json['mon_active']
    tues_active = request.json['tues_active']
    wed_active = request.json['wed_active']
    thurs_active = request.json['thurs_active']
    fri_active = request.json['fri_active']
    sat_active = request.json['sat_active']
    sun_active = request.json['sun_active']

    new_bus = Bus(name,src,dest,s_time,e_time,price,no_seats,rem_seats,
    mon_active,tues_active,wed_active,thurs_active,fri_active,sat_active,sun_active)

    db.session.add(new_bus)
    db.session.commit()
    return bus_schema.jsonify(new_bus)

#find bus
@app.route('/findbuses',methods=['POST'])
def find_bus():
    db_src = request.json['src']
    db_dest = request.json['dest']
    db_date = request.json['date']
    day, month, year = (int(x) for x in db_date.split('/'))
    res_day = datetime.date(year, month, day)
    res_day.strftime("%A")

    bus = Bus.query.filter_by(src = db_src,dest = db_dest,).order_by(Bus.price)
    result = buses_schema.dump(bus)
    return jsonify(result)

#reserve seats
@app.route('/reserveseats',methods=['POST'])
def reserve_seats():
    db_b_id = request.json['b_id']
    db_seats = request.json['no_seats']
    db_u_id = request.json['u_id']

    curr_bus = Bus.query.get(db_b_id)
    if(curr_bus.rem_seats >= db_seats):
        curr_bus.rem_seats = curr_bus.rem_seats - db_seats
        db.session.commit()

    new_reservation = Reservations(db_u_id, db_b_id, db_seats)
    db.session.add(new_reservation)
    db.session.commit()

    return reservation_schema.jsonify(new_reservation)

#get all reservations
@app.route('/getreservations',methods=['POST'])
def get_reservations():
    db_u_id = request.json['u_id']
    all_reservations = Reservations.query.all()
    result = reservations_schema.dump(all_reservations)
    return jsonify(result)

if __name__ == '__main__':
    app.run(debug=True)
