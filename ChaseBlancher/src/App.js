import React, { useState } from 'react';
import $ from 'jquery'; 
import './App.css';


function MyButton({onClick})
  {
    return ( 
      <button onClick={onClick}>
        Generate Poem
        
      </button>
    );
    //contains the button title and passes the onClick callback
  }

function App() {

  const [quotes, setQuotes] = useState([]);
  const [selectedCategory, setSelectedCategory] = useState('');
  //variables to set the quote and the category
  const categories = [
    "All",
    "Age",
    "Alone",
    "Amazing",
    "Anger",
    "Architecture",
    "Art",
    "Attitude",
    "Beauty",
    "Best",
    "Birthday",
    "Business",
    "Car",
    "Change",
    "Communication",
    "Computers",
    "Cool",
    "Courage",
    "Dad",
    "Dating",
    "Death",
    "Design",
    "Dreams",
    "Education",
    "Environmental",
    "Equality",
    "Experience",
    "Failure",
    "Faith",
    "Family",
    "Famous",
    "Fear",
    "Fitness",
    "Food",
    "Forgiveness",
    "Freedom",
    "Friendship",
    "Funny",
    "Future",
    "God",
    "Good",
    "Government",
    "Graduation",
    "Great",
    "Happiness",
    "Health",
    "History",
    "Home",
    "Hope",
    "Humor",
    "Imagination",
    "Inspirational",
    "Intelligence",
    "Jealousy",
    "Knowledge",
    "Leadership",
    "Learning",
    "Legal",
    "Life",
    "Love",
    "Marriage",
    "Medical",
    "Men",
    "Mom",
    "Money",
    "Morning",
    "Movies",
    "Success"
  ];
  //list of categories
  const fetchQuotes = () => {
    let category = '';
    if(selectedCategory !== 'All') {
      category = `?category=${selectedCategory}`;
    }
    //const category = 'Movies';
    $.ajax({
        method: 'GET',
        url: 'https://api.api-ninjas.com/v1/quotes?category=',
        headers: { 'X-Api-Key': process.env.REACT_APP_API_KEY},
        contentType: 'application/json',
        success: function(result) {
            setQuotes(result);
        },
        // sets the quotes with the data from the api
        error: function ajaxError(jqXHR) {
            console.error('Error: ', jqXHR.responseText);
        }
    },);
    //if there is an error the console throws an error
  };

  const HandleCategoryChange = (event) => {
    setSelectedCategory(event.target.value);
  };

  return (
    <div className = "app">
      <h1>
        Poem Generator
      </h1>
      <p>
        Select the category to generate a poem of your liking!
      </p>
      <div className = "Controls">
        <select onChange={HandleCategoryChange}>
          {categories.map((category, index) => (
            <option key={index} value={category}>
              {category}
            </option>
          ))}
        </select>
          <MyButton onClick={fetchQuotes}/>
      </div>
      <div className = "output">
        {/* Assuming your API returns an array of quote objects */}
        {quotes.map((quote, index) => (
          <div key={index}>
            <p>{quote.quote} - {quote.author}</p> {/* Adjust these fields based on your API response */}
          </div>
        ))}
      </div>
    </div>
  );

}

export default App;
