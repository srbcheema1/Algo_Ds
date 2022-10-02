
    int findKthLargest(vector<int>& nums, int k) 
    {
        if( k == 1 )
        {
            int mv = INT_MIN;
            for( size_t i = 0; i < nums.size(); ++i)          
                mv = std::max(mv,nums[i]);
            
            return mv;        
        }
        else
        {
            vector<int> heap;
            for( size_t i = 0; i < nums.size(); ++i)
                pushHeap(heap, k, nums[i]);
            
            return heap[0];       
        }
    }

    void pushHeap(vector<int>& heap, int k, int v)
    {
        // cout << "Push: " << v << endl;
        
        if( heap.size() == (size_t)k )
        {
            if( v <= heap[0] ) 
                return; 
            
            //Adjust Heap
            heap[0] = v;
            adjustHeap(heap, k, 0 );
        }
        else
        {
            heap.push_back(v);
            
            // Build Heap
            if( heap.size() == (size_t)k )
            {
                for(int pos = k/2-1; pos >= 0; --pos)
                {
                    int posL = 2*pos+1;
                    int posR = posL+1;
                    
                    if( heap[posL] < heap[pos] )
                    {
                        swap( heap, posL, pos);
                        adjustHeap(heap, k , posL);
                    }
                    
                    if(posR < k && heap[posR] < heap[pos] )
                    {
                        swap( heap, posR, pos);
                        adjustHeap(heap, k , posR);
                    }
                }
                
                // cout << "Build: " << heap << endl;
            }
        }
    }
    
    void adjustHeap(vector<int>& heap, int k, int pos)
    {
        while (pos <= (k/2-1))
        {
            int child = 2*pos+1; 

            if( (child + 1) < k && heap[child] > heap[child+1])
                ++child;

            if( heap[pos] <= heap[child])
                break;

            swap( heap, pos, child);
            pos = child;
        }

        // cout << "Adjust: " << heap << endl;
    }

    void swap(vector<int>& heap, int a, int b)
    {
        int t = heap[a];
        heap[a] = heap[b];
        heap[b] = t;
    }
