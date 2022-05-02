import json
from flask import Flask, request, abort
from dotenv import dotenv_values
from skola_online import SkolaOnline
from fablab import Fablab
from salina import Salina
from alojz import Alojz
from functools import wraps
import datetime

app = Flask(__name__)

# file .env
# USERNAME=username
# PASSWORD=password
# API_KEY=api_key
config = dotenv_values(".env")


def request_message(message):
    mess = {"message": message, "status": "ok", "time": str(datetime.datetime.now())}
    print(mess)
    return json.dumps(mess)


def request_error(message):
    mess = {"message": message, "status": "error"}
    print(mess)
    return json.dumps(mess)


# Source: https://coderwall.com/p/4qickw/require-an-api-key-for-a-route-in-flask-using-only-a-decorator
# The actual decorator function
def require_appkey(view_function):
    @wraps(view_function)
    # the new, post-decoration function. Note *args and **kwargs here.
    def decorated_function(*args, **kwargs):
        config = dotenv_values(".env")
        if request.args.get("api_key") and request.args.get("api_key") == config["API_KEY"]:
            return view_function(*args, **kwargs)
        else:
            abort(401)

    return decorated_function


# http://127.0.0.1:5000/marksLast/?api_key=
# @require_apikey
@app.route("/marksLast/")
def marksLastFlask():
    """! @brief URL pro získání posledních známek.

    @return JSON s posledními známkami
    """

    try:
        sol = SkolaOnline(config["USERNAME"], config["PASSWORD"])
        lastMarks = sol.getLastMarks()

        json_arr = []
        for mark in lastMarks:
            print(mark)
            json_arr.append(mark.__dict__)
        return request_message(json_arr)

    except Exception as e:
        return request_error(str(e))


# http://127.0.0.1:5000/marksSubject/
# @require_apikey
@app.route("/marksSubject/")
def marksSubjectFlask():
    """! @brief URL pro získání známek podle předmětu.

    @return JSON se známkami podle předmětu
    """

    return request_error("Neni implementovano :-(")

    try:
        sol = SkolaOnline(config["USERNAME"], config["PASSWORD"])
        subject = request.args.get("subject")
        lastMarks = sol.getLastMarksBySubject(subject)

        json_arr = []
        for mark in lastMarks:
            print(mark)
            json_arr.append(mark.__dict__)
        return request_message(json_arr)

    except Exception as e:
        print(e)
        return request_error(str(e))


# http://127.0.0.1:5000/fablabNow/
# @require_apikey
@app.route("/fablabNow/")
def fablabNowFlask():
    """! @brief URL pro získání aktuálního stavu strojů ve Fsblabu.
    @return JSON s aktuálním stavem strojů ve Fsblabu
    """

    return request_error("Neni implementovano :-(")

    try:
        fablab = Fablab()
        machinesStat = fablab.getMachinesStatus()

        json_arr = []
        for machine in machinesStat:
            print(machine)
            json_arr.append(machine.__dict__)
        return request_message(json_arr)

    except Exception as e:
        print(e)
        return json.dumps({"error": str(e)})

# http://127.0.0.1:5000/departures?stopid=1272&postid=2
# @require_apikey
@app.route("/departures")
def departuresFlask():
    params = request.args

    # {'stopid': '1146', 'postid': '1'}
    if not params.get("stopid") or not params.get("postid"):
        return request_error("Není zadáno stop_id nebo post_id")
    try:
        salina = Salina()
        salinaStop = salina.getDepartures(params)
        return request_message(salinaStop)
    except Exception as e:
        print(e)
        return request_error(str(e))


# http://127.0.0.1:5000/alojz?alojzId=brno&lat=49.195060&lon=16.606837&alt=237
# @require_apikey
@app.route("/alojz")
def alojzFlask():
    params = request.args

    # {"alojzId": "brno", "lat": 49.195060, "lon": 16.606837, "alt": 237}
    if not params.get("alojzId") or not params.get("lat") or not params.get("lon") or not params.get("alt"):
        return request_error("Není zadáno alojzId, lat, lon nebo alt")
    try:
        alozj = Alojz()
        alojzWeather = alozj.getWeather(params)
        return request_message(alojzWeather)
    except Exception as e:
        print(e)
        return request_error(str(e))


if __name__ == "__main__":
    """! @brief Spouštění aplikace.
    Hlavní funkce aplikace - spouští Flask server.
    """

    app.run(host="0.0.0.0")
    # app.run(debug=True, host="0.0.0.0")
