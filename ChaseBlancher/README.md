# Poem Generator

The Poem Generator is a React web application that allows users to generate poems based on a selected category. Utilizing the API Ninja's Quotes API, this app fetches and displays quotes that resonate as poems, offering inspiration and reflection across a wide range of themes.

## Installation

To get started with the Poem Generator, follow these steps:

1. Clone this repository to your local machine.

   ```bash
   git clone https://your-repository-url-here.git
   cd poem-generator
   ```

2. Install the necessary dependencies.

   ```bash
   npm install
   ```

3. Create a `.env` file in the root of your project and add your API Ninja's Quotes API key as follows:

   ```plaintext
   REACT_APP_API_KEY=your_api_key_here
   ```

   This file and variable allow the application to authenticate with the API service.

4. Start the development server.

   ```bash
   npm start
   ```

   The application should now be running and accessible at `http://localhost:3000`.

## Getting Your API Key

The application requires an API key from API Ninjas to fetch quotes. To obtain your API key:

1. Visit [API Ninjas](https://api-ninjas.com/) and sign up for an account.
2. Navigate to the API keys section and generate a new API key.
3. Copy your API key and follow the installation instructions above to add it to your `.env` file.

## Using the Application

To use the Poem Generator:

1. Open the application in your web browser.
2. Use the dropdown menu to select a category for your poem. You can choose from a wide range of themes, such as Love, Nature, Inspiration, and many more.
3. Click the "Generate Poem" button to fetch and display a poem based on the selected category.
4. Read and enjoy the generated poem. You can select a new category and generate new poems as many times as you like.

## Features

- **Category Selection:** Choose from a diverse list of categories to tailor the type of poem you want to generate.
- **Dynamic Poem Generation:** Each click of the "Generate Poem" button fetches a new poem related to the selected category.
- **Responsive Design:** Enjoy a simple, user-friendly interface that works across various devices and screen sizes.

For any questions or contributions, please refer to the project's GitHub issues or pull requests sections.

Enjoy exploring the art of poetry with the Poem Generator!
