# cs210-programming-languages
Repository dedicated to projects from my CS-210 Programming Languages course.

# The Project
Airgead Banking requested a program to help teach students fiscal responsibility through an interactive application to evaluate investments and compound interest over time.

# What Went Well
While designing my code, I felt confident in the modular design of the functions. Common functions such as retrieving monthly deposit, formatting money for display, validating menu input, etc. were called frequently in other functions. This enabled me to adjust particular code block that would take effect when the function was called by others.

# Improvements, Security, Etc.
Thinking back on the project, I'd decrease the valid input years to model the savings. I had limited it to 100 years, though this would not likely be applicable for students. Perhaps a limit of 75 years would have been more appropriate. Additionally, I would have made some of the public member functions private as likely just the InvestmentCalculator class would be using them, such as the print menu, print user menu top border, etc. By these being public, classes outside of the intended InvestmentCalculator class could access them, when they shouldn't be accessed by the program.

# Challenges
I found that printing the reports side-by-side was challenging because I had previously written them individually. I was unsure of how to get them to display together by calling the functions as they existed. I found that I could keep both modular functions to create each report by sending their output to separate output string streams. I then used input string streams to read through the reports line by line, treating the report without deposits as the left line and the report with deposits as the right line. Finally, I displayed each left line, followed by a separator and the corresponding right line, for each row of both tables.

# Transferrable Skills
I was able to get acquainted with the string stream better in this project. Using this in upcoming projects will help any time I need to read data from files, parse through mixed-type data, and help validation situations like reaching the end of a file or if there was a failure at any point.

# Maintainability, Readability, Adaptability
I kept the program easy to read and maintain through description variable naming that followed Airgead Banking's Standards where specific naming conventions were required for unifying code design. The modular design of the functions allows for re-use in future expansion of the program, without sacrificing or needing to change existing functionality.
