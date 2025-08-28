import './App.css';
import Quadrante from './Quadrante'
import { useEffect, useState } from 'react';

function App() {
  const [data, setData] = useState(null);

  const hostIp = process.env.REACT_APP_API_IP;

  useEffect(() => {
    const fetchData = async () => {
      try {

        const response = await fetch(`http://${hostIp}:8080/api/MPU6050/data/`, { method: "GET" });

        if (response.ok) {
          const result = await response.json();
          setData(result);
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
        <div className="sensor-div">
          {Object.keys(data).map((key, index) => {
            return <Quadrante name={key} data={data[key]} />;
          })}
        </div>
      ) : (
        <p>Loading data...</p>
      )}
    </div>
  );
}

export default App;
