# Binary Data Graph
This is a web application to draw graph of binary data.   
<img width="300" src="https://user-images.githubusercontent.com/74242663/103348615-e3805b80-4add-11eb-946c-93c60f4a9b0e.png">

## Prerequisites
This application requires python and some python packages.   
Please install some packages before run this application.   
Install commands using 'pip' are shown below.   

* Install *Django* package   
`> pip install django`   
* Install *plotly* package   
`> pip install plotly`   
* Install *pandas* package   
`> pip install pandas`   

## Create database tables
First of all, you have to create database tables to run this application.   
The commands are shown below.   
* `django_plotly> python manage.py makemigrations graph`   
* `django_plotly> python manage.py migrate`   

You can see 'db.sqlite3' in django_plotly directory.   
After then, you don't need to do this procedure everytime.

## Run
### Run standalone
You can run this application by putting below command.   
* `django_plotly> python manage.py runserver`   

And you can see the web page, which is serviced by this application, on your browser.   
Address is `127.0.0.1:8000`   
You can upload your binary files or define its data structures.   
Also, you can plot binary data on a graph.   

### Get access through other devices in the local network
If you want to get access to this application on other devices, you have to change the server address.   
The address is your local network address like 192.168.0.50.   
Change 'django_plotly/django_plotly/settings.py'.   
> ALLOWED_HOSTS = ['192.168.0.50']

Then, run this application.   
* `django_plotly> python manage.py runserver 192.168.0.50:8000`   

## Test environment
* Windows 10 64bit
* Microsoft Edge 87.0.664.66
* python 3.9.0
* Django 3.1.3
* plotly 4.12.0
* pandas 1.1.4
