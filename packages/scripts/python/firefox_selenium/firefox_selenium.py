import logging
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import Select, WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.firefox.service import Service
from selenium.common.exceptions import NoSuchElementException, TimeoutException

# Configure logging for better tracking of the script's execution and issues
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

# Create a Service object with the executable path for GeckoDriver
service = Service(r'.\geckodriver-v0.34.0-win64\geckodriver.exe')

# Initialize the Firefox driver with the Service object
driver = webdriver.Firefox(service=service)

# Personal data for the Gmail account to be created
your_first_name = "Jhon"
your_last_name = "Doemen"
your_username = "Jhon12Doemen"
your_birthday = "02 3 1999"
your_gender = "1"  # Gender options: 1 for Female, 2 for Male, 3 for Prefer not to say, 4 for Custom
your_password = "x,nscldsj123...FDKZ"

try:
    # Navigate to the Gmail account creation page
    driver.get("https://accounts.google.com/signup/v2/createaccount?flowName=GlifWebSignIn&flowEntry=SignUp")

    # Locate and fill the first and last name fields
    first_name = driver.find_element(By.NAME, "firstName")
    last_name = driver.find_element(By.NAME, "lastName")
    first_name.clear()
    first_name.send_keys(your_first_name)
    last_name.clear()
    last_name.send_keys(your_last_name)

    # Click the 'Next' button to proceed
    next_button = driver.find_element(By.CLASS_NAME, "VfPpkd-vQzf8d")
    next_button.click()

    # Explicit wait for birthday fields to be visible and interactable
    wait = WebDriverWait(driver, 20)
    wait.until(EC.visibility_of_element_located((By.NAME, "day")))

    # Split the birthday string to separate day, month, and year
    birthday_elements = your_birthday.split()

    # Select the birthday month, day, and year
    month_dropdown = Select(driver.find_element(By.ID, "month"))
    month_dropdown.select_by_value(birthday_elements[1])
    day_field = driver.find_element(By.ID, "day")
    day_field.clear()
    day_field.send_keys(birthday_elements[0])
    year_field = driver.find_element(By.ID, "year")
    year_field.clear()
    year_field.send_keys(birthday_elements[2])

    # Select the gender
    gender_dropdown = Select(driver.find_element(By.ID, "gender"))
    gender_dropdown.select_by_value(your_gender)

    # Click the 'Next' button to proceed
    next_button = driver.find_element(By.CLASS_NAME, "VfPpkd-vQzf8d")
    next_button.click()

    # Create a custom email username
    wait.until(EC.element_to_be_clickable((By.ID, "selectioni3"))).click()
    wait.until(EC.element_to_be_clickable((By.NAME, "Username"))).send_keys(your_username)
    
    # Click the 'Next' button to proceed
    next_button = driver.find_element(By.CLASS_NAME, "VfPpkd-vQzf8d")
    next_button.click()
    
    # Set and confirm the account password
    password_field = wait.until(EC.visibility_of_element_located((By.NAME, "Passwd")))
    password_field.clear()
    password_field.send_keys(your_password)
    password_confirmation_field = driver.find_element(By.NAME, "PasswdAgain")
    password_confirmation_field.clear()
    password_confirmation_field.send_keys(your_password)
    
  

    # Skip adding phone number and recovery email
    for _ in range(2):
        wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "button span.VfPpkd-vQzf8d"))).click()

    # Agree to Google's terms and privacy
    wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "button span.VfPpkd-vQzf8d"))).click()

    # Close the browser after account creation
    driver.quit()

    # Log the successful creation of the account
    logging.info("Your Gmail successfully created: {\ngmail: %s@gmail.com\npassword: %s\n}", your_username, your_password)

# Catch specific exceptions and log errors
except NoSuchElementException as e:
    logging.error("Element not found in the page: %s", e)
    driver.quit()

except TimeoutException as e:
    logging.error("Loading took too much time: %s", e)
  

except Exception as e:
    logging.error("An unexpected error occurred: %s", e)
    driver.quit()
