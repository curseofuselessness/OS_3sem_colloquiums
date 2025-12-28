document.addEventListener('DOMContentLoaded', function() {
    console.log('форма загружена!');

    const form = document.getElementById('create-task-form');
    const messageDiv = document.getElementById('message');

    form.addEventListener('submit', async function(event) {
        event.preventDefault();

        messageDiv.innerHTML = '<span style="color: blue;">⏳ Отправка...</span>';
        messageDiv.style.display = 'block';

        const formData = {
            title : document.getElementById('title').value.trim(),
            description: document.getElementById('description').value.trim(),
        }

        try {
            const response = await fetch('http://192.168.1.3:5000/sendtask', {
                
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify(formData)
            });

            if (response.ok) {
                const result = await response.json();
                console.log('пошел');
                messageDiv.innerHTML = `<span style="color: green;">Задача создана успешно!</span><br>
                                        <small>ID: ${result.id}, Название: ${result.title}</small>`;
                
                form.reset();
                
                setTimeout(() => {messageDiv.style.display = 'none';}, 5000);
                
            } else {
                // Ошибка на сервере
                const errorData = await response.json();
                messageDiv.innerHTML = `<span style="color: red;">Ошибка ${response.status}: ${errorData.error || 'Неизвестная ошибка'}</span>`;
            }
            
        } catch (error) {
            // Ошибка соединения с сервером
            console.error('Ошибка сети:', error);
            messageDiv.innerHTML = `<span style="color: red;">Не удалось соединиться с сервером!</span><br>
                                    <small>Убедитесь, что Flask сервер запущен на localhost:5000</small>`;
        }
    })
})