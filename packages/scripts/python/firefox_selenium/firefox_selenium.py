from selenium import webdriver
from selenium.webdriver.firefox.service import Service

# Create a Service object with the executable path (GeckoDriver)
service = Service(r'.\geckodriver-v0.34.0-win64\geckodriver.exe')

# Initialize the Firefox driver with the Service object
driver = webdriver.Firefox(service=service)


driver.get('https://github.com')