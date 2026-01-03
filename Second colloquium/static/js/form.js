document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('create-task-form');
    const messageDiv = document.getElementById('message');

    console.log('форма загружена!');

    form.addEventListener('submit', async function(event) {
        event.preventDefault();

        messageDiv.style.display = 'block';

        const formData = getFormData(form);

        const result = await sendTaskData(formData);

        if(result) updateTaskList(result);
    
    })

    function getFormData(form) {
        const formData = {
            title : document.getElementById('title').value.trim(),
            description: document.getElementById('description').value.trim(),
        }
        return formData;
    }

    async function sendTaskData(formData) {
        try {
            const response = await fetch('/sendtask', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(formData)
            });

            if (response.ok) {
                showMessage(messageDiv, 'Задача создана успешно!', 'success');
        
                form.reset();
                
                setTimeout(() => {messageDiv.style.display = 'none';}, 5000);

                return await response.json();
                
            } else {
                // Ошибка на сервере
                const errorData = await response.json();
                showMessage(messageDiv, 'Ошибка на сервере!', 'error');
            }
            
        } catch (error) {
            // Ошибка соединения с сервером
            console.error('Ошибка сети:', error);
            showMessage(messageDiv, 'Ошибка сети!', 'error')
        }
    }

    function updateTaskList(result) {
        const tasklist = document.getElementById('tasks-list');
        const emptystate = document.querySelector('.empty-list-message');

        if(emptystate) emptystate.remove();

        const taskElement = createTaskObject(result);
        tasklist.prepend(taskElement);
    }

    function createTaskObject(result) {
        const div = document.createElement('div');

        div.className = 'task-card-temp';
        div.innerHTML = result.html;

        return div;
    }

    function showMessage(element, message, type = 'info') {
        const colors = {
            loading: 'blue',
            success: 'green',
            error: 'red',
            info: 'gray'
        };
        
        element.innerHTML = `<span style="background-color: ${colors[type] || 'white'}; border-radius: 10px;  padding: 10px;">${message}</span>`;
        element.style.display = 'block';
    }
});



