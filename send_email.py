import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Email configuration
sender_email = "your_email@gmail.com"
receiver_email = "recipient_email@gmail.com"
password = "your_password"
subject = "Subject of your email"
message = "This is the body of your email."

# Create the email content
msg = MIMEMultipart()
msg['From'] = sender_email
msg['To'] = receiver_email
msg['Subject'] = subject
msg.attach(MIMEText(message, 'plain'))

# Initialize the SMTP server
smtp_server = "smtp.gmail.com"  # Use the SMTP server of your email provider
smtp_port = 587  # Port number (587 for TLS, 465 for SSL)
try:
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()  # Enable TLS (Transport Layer Security)
    server.login(sender_email, password)
    
    # Send the email
    text = msg.as_string()
    server.sendmail(sender_email, receiver_email, text)
    print("Email sent successfully!")
except Exception as e:
    print(f"An error occurred: {str(e)}")
finally:
    server.quit()  # Close the SMTP server

