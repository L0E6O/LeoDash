import './App.css';
import { useEffect, useState } from 'react';

function App() {
  const [data, setData] = useState(null);

  useEffect(() => {
    const fetchData = async () => {
      try {
        
        const response = await fetch(`172.20.10.5:8080/api/MPU6050/data/`, {method: "GET"});

        console.log(response);
        
        
        if (response.ok) {
          const result = await response.json();
          setData(result);
          console.log(result);
        } else {
          console.error('Failed to fetch data:', response.status);
        }
      } catch (error) {
        console.error('Error fetching data:', error);
      }
    };

    // Call immediately
    fetchData();

    // Set up interval
    const interval = setInterval(fetchData, 200);

    // Cleanup function to clear interval
    return () => clearInterval(interval);
  }, []); // Empty dependency array means this runs once on mount

  return (
    <div className="App">
      {data ? (
        <pre>{JSON.stringify(data, null, 2)}</pre>
      ) : (
        <p>Loading data...</p>
      )}
    </div>
  );
}

export default App;